#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

#include <mysql/jdbc.h>
#include <iostream>

#include <vector>
#include <string>


using namespace std;

// 데이터베이스 연결 정보 설정
const string DB_HOST = "tcp://127.0.0.1:3306";  // MySQL 서버 주소와 포트
const string DB_USER = "root";                  // MySQL 사용자 이름
const string DB_PASS = "1234";                  // MySQL 비밀번호
const string DB_NAME = "socket";                // 사용할 데이터베이스 이름

// 네트워크 설정
const int PORT = 12345;                         // 서버가 사용할 포트 번호
const int BUFFER_SIZE = 1024;                   // 데이터 송수신 버퍼 크기



// 메인 함수
int main() {
    WSADATA wsaData;

    // 윈도우 소켓 초기화
    if (!initializeWinsock(wsaData)) {
        return 1;
    }

    // 서버 소켓 생성
    SOCKET serverSocket = createServerSocket();
    if (serverSocket == INVALID_SOCKET) {
        return 1;
    }

    // 서버 소켓 바인딩
    if (!bindServerSocket(serverSocket, PORT)) {
        return 1;
    }

    // 클라이언트 연결 대기
    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        cerr << "Listen failed." << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    cout << "[서버 시작] " << PORT << " 포트 대기중....\n";

    // 클라이언트 연결 처리 루프
    while (true) {
        SOCKET clientSocket = accept(serverSocket, NULL, NULL);
        if (clientSocket != INVALID_SOCKET) {
            cout << "클라이언트 연결됨" << endl;
            handleClient(clientSocket);
        }
    }

    // 서버 종료 시 정리
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}
// 윈도우 소켓 초기화 함수
// WSAStartup을 호출하여 윈도우 소켓 라이브러리를 초기화
bool initializeWinsock(WSADATA& wsaData) {
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cerr << "WSAStartup 실패" << endl;
        return false;
    }
    return true;
}

// 서버 소켓 생성 함수
// TCP/IP 소켓을 생성하고 반환
SOCKET createServerSocket() {
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        cerr << "Socket creation failed." << endl;
        WSACleanup();
        return INVALID_SOCKET;
    }
    return serverSocket;
}

// 서버 소켓 바인딩 함수
// 서버 소켓을 지정된 포트에 바인딩
bool bindServerSocket(SOCKET serverSocket, int port) {
    SOCKADDR_IN serverAddr;
    serverAddr.sin_family = AF_INET;            // IPv4 주소 체계 사용
    serverAddr.sin_port = htons(port);          // 포트 번호 설정
    serverAddr.sin_addr.s_addr = INADDR_ANY;    // 모든 네트워크 인터페이스에서 연결 허용

    // bind 함수의 반환값 확인 (SOCKET_ERROR는 -1)
    if (bind(serverSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        // 소켓 바인딩 실패
        std::cerr << "Socket bind failed.\n";
        // 서버 소켓 종료
        closesocket(serverSocket);
        // 윈도우 소켓 초기화 취소
        WSACleanup();
        return 1;
    }
    return true;
}

// 로그인 처리 함수
// 사용자 이름과 비밀번호를 데이터베이스에서 확인
bool processLogin(const string& name, const string& pass, SOCKET clientSocket) {
    try {
        // MySQL 드라이버 인스턴스 생성 및 데이터베이스 연결
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
        sql::Connection* con = driver->connect(DB_HOST, DB_USER, DB_PASS);
        con->setSchema(DB_NAME);

        // 사용자 인증을 위한 SQL 쿼리 준비
        unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement("SELECT * FROM users WHERE name = ? AND password = ?"));
        pstmt->setString(1, name);
        pstmt->setString(2, pass);
        unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

        // 로그인 성공 여부 확인
        bool loginSuccess = res->next();

        // 클라이언트에게 로그인 결과 전송
        string responseMsg = loginSuccess ?
            "LOGIN:SUCCESS\n" :
            "LOGIN:ERROR:Invalid username or password\n";
        send(clientSocket, responseMsg.c_str(), responseMsg.size(), 0);

        // 데이터베이스 연결 종료
        delete con;
        return loginSuccess;
    }
    catch (sql::SQLException& e) {
        // 데이터베이스 오류 발생 시 처리
        string errorMsg = "ERROR:Database connection failed\n";
        send(clientSocket, errorMsg.c_str(), errorMsg.size(), 0);
        cout << "SQL 오류: " << e.what() << endl;
        return false;
    }
}

// 로그인 메시지 파싱 함수
// 클라이언트로부터 받은 로그인 메시지를 분석하여 사용자 정보 추출
bool parseLoginMessage(const string& msg, string& name, string& pass) {
    // 메시지 형식: LOGIN:username:password:
    size_t pos1 = msg.find(":", 6);    // 첫 번째 콜론 위치
    size_t pos2 = msg.find(":", pos1 + 1);  // 두 번째 콜론 위치

    if (pos1 == string::npos || pos2 == string::npos) {
        return false;  // 잘못된 메시지 형식
    }

    // 사용자 이름과 비밀번호 추출
    name = msg.substr(6, pos1 - 6);
    pass = msg.substr(pos1 + 1, pos2 - pos1 - 1);

    cout << "Name: " << name << endl;  // 디버깅용 출력
    cout << "Pass: " << pass << endl;  // 디버깅용 출력

    return true;
}

// 메시지 에코 처리 함수
// 클라이언트로부터 받은 메시지를 그대로 다시 전송
void handleMessages(SOCKET clientSocket) {
    vector<char> buffer(BUFFER_SIZE, 0);
    bool connected = true;

    while (connected) {
        memset(buffer.data(), 0, buffer.size());
        int bytesRead = recv(clientSocket, buffer.data(), buffer.size(), 0);

        if (bytesRead <= 0) {
            connected = false;
            break;
        }

        string receivedMsg(buffer.data(), bytesRead);
        cout << "받은 메시지: " << receivedMsg << endl;

        // 받은 메시지를 그대로 클라이언트에게 전송
        send(clientSocket, receivedMsg.c_str(), receivedMsg.size(), 0);
    }
}

// 클라이언트 처리 함수
// 클라이언트의 연결을 처리하는 메인 함수
void handleClient(SOCKET clientSocket) {
    vector<char> buffer(BUFFER_SIZE, 0);

    // 클라이언트로부터 초기 메시지 수신
    int bytesRead = recv(clientSocket, buffer.data(), buffer.size(), 0);

    if (bytesRead <= 0) {
        closesocket(clientSocket);
        return;
    }

    string msg(buffer.data(), bytesRead);
    cout << "[RECV] : " << msg << endl;

    // 로그인 메시지 처리
    if (msg.rfind("LOGIN", 0) == 0) {
        string name, pass;

        // 로그인 메시지 파싱
        if (!parseLoginMessage(msg, name, pass)) {
            string errorMsg = "LOGIN:ERROR:Invalid command format\n";
            send(clientSocket, errorMsg.c_str(), errorMsg.size(), 0);
            closesocket(clientSocket);
            return;
        }

        // 로그인 성공 시 메시지 처리 시작
        if (processLogin(name, pass, clientSocket)) {
            handleMessages(clientSocket);
        }
    }
    else {
        // 잘못된 명령 처리
        string errorMsg = "ERROR:Invalid command\n";
        send(clientSocket, errorMsg.c_str(), errorMsg.size(), 0);
    }

    closesocket(clientSocket);
}