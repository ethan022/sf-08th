#include <iostream>     // 입출력 스트림 헤더
#include <WinSock2.h>   // Windows 소켓 기본 헤더
#include <WS2tcpip.h>   // TCP/IP 확장 기능 헤더
#include <string>       // 문자열 처리 헤더

#pragma comment(lib, "ws2_32.lib")  // 윈속 라이브러리 링크

using namespace std;

// 프로그램에서 사용할 상수 정의
const int PORT = 12345;           // 서버 포트 번호
const int BUFFER_SIZE = 1024;     // 버퍼 크기
const char* SERVER_IP = "127.0.0.1"; // 서버 IP 주소

// 윈속 초기화 함수
bool initializeWinsock(WSADATA& wsaData) {
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cerr << "윈속 초기화 실패: " << WSAGetLastError() << endl;
        return false;
    }
    return true;
}

// 클라이언트 소켓 생성 함수
SOCKET createClientSocket() {
    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        cerr << "소켓 생성 실패: " << WSAGetLastError() << endl;
        WSACleanup();
        return INVALID_SOCKET;
    }
    return clientSocket;
}

// 서버 연결 함수
bool connectToServer(SOCKET clientSocket, const char* serverIP, int port) {
    SOCKADDR_IN serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    inet_pton(AF_INET, serverIP, &serverAddr.sin_addr);
    
    if (connect(clientSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        cerr << "서버 연결 실패: " << WSAGetLastError() << endl;
        return false;
    }
    
    cout << "서버에 연결되었습니다." << endl;
    return true;
}

// 로그인 처리 함수
bool handleLogin(SOCKET clientSocket) {
    // 사용자 인증 정보 입력 받기
    string username, password;
    cout << "아이디: ";
    getline(cin, username);
    cout << "비밀번호: ";
    getline(cin, password);
    
    // 로그인 메시지 형식: LOGIN:사용자명:비밀번호:
    string loginMessage = "LOGIN:" + username + ":" + password + ":";
    cout << "서버로 로그인 정보 전송중..." << endl;
    
    // 로그인 정보 전송
    if (send(clientSocket, loginMessage.c_str(), static_cast<int>(loginMessage.length()), 0) == SOCKET_ERROR) {
        cerr << "로그인 정보 전송 실패: " << WSAGetLastError() << endl;
        return false;
    }
    
    // 서버 응답 대기
    char buffer[BUFFER_SIZE] = {0};
    int bytesReceived = recv(clientSocket, buffer, BUFFER_SIZE, 0);
    
    // 응답 처리
    if (bytesReceived > 0) {
        // 수신된 데이터를 문자열로 변환
        string response(buffer, bytesReceived);
        cout << "[서버 응답] " << response << endl;
        
        // 로그인 실패시 false 반환
        if (response.find("LOGIN:ERROR") != string::npos) {
            cout << "로그인 실패. 프로그램을 종료합니다." << endl;
            return false;
        }
        return true; // 로그인 성공
    }
    else if (bytesReceived == 0) {
        // 서버가 연결을 정상적으로 종료
        cerr << "서버가 연결을 종료했습니다." << endl;
        return false;
    }
    else {
        // 오류 발생
        cerr << "서버 응답 수신 실패: " << WSAGetLastError() << endl;
        return false;
    }
}

// 메시지 송수신 함수
void communicateWithServer(SOCKET clientSocket) {
    char buffer[BUFFER_SIZE] = {0};
    
    cout << "로그인 성공! 메시지를 입력하세요." << endl;
    
    // 메시지 송수신 루프
    while (true) {
        // 사용자 입력 받기
        string userInput;
        cout << "메시지 입력 (종료: exit): ";
        getline(cin, userInput);
        
        // 종료 명령 확인
        if (userInput == "exit") {
            cout << "채팅을 종료합니다." << endl;
            break;
        }
        
        // 메시지 전송
        if (send(clientSocket, userInput.c_str(), userInput.length(), 0) == SOCKET_ERROR) {
            cerr << "메시지 전송 실패: " << WSAGetLastError() << endl;
            break;
        }
        
        // 서버 응답 수신
        memset(buffer, 0, BUFFER_SIZE);
        int recvLen = recv(clientSocket, buffer, BUFFER_SIZE, 0);
        
        // 응답 처리
        if (recvLen > 0) {
            // 수신된 데이터를 문자열로 변환
            string echo(buffer, recvLen);
            cout << "서버 응답: " << echo << endl;
        }
        else if (recvLen == 0) {
            // 서버가 연결을 정상적으로 종료
            cout << "서버와 연결이 종료되었습니다." << endl;
            break;
        }
        else {
            // 오류 발생
            cerr << "메시지 수신 실패: " << WSAGetLastError() << endl;
            break;
        }
    }
}

// 클라이언트 종료 함수
void cleanup(SOCKET clientSocket) {
    // 소켓 종료
    closesocket(clientSocket);
    // 윈속 라이브러리 해제
    WSACleanup();
    
    cout << "프로그램을 종료합니다." << endl;
}

int main() {
    // 필요한 변수 선언
    WSADATA wsaData;
    SOCKET clientSocket;
    
    // 윈속 초기화
    if (!initializeWinsock(wsaData)) {
        return 1;
    }
    
    // 클라이언트 소켓 생성
    clientSocket = createClientSocket();
    if (clientSocket == INVALID_SOCKET) {
        return 1;
    }
    
    // 서버 연결
    if (!connectToServer(clientSocket, SERVER_IP, PORT)) {
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }
    
    // 로그인 처리
    if (!handleLogin(clientSocket)) {
        closesocket(clientSocket);
        WSACleanup();
        return 0;
    }
    
    // 메시지 송수신
    communicateWithServer(clientSocket);
    
    // 종료 처리
    cleanup(clientSocket);
    
    return 0;
}