# 네트워크 프로그래밍 & MySQL 연동

## 📖 개요

C++로 소켓 프로그래밍과 MySQL 데이터베이스를 연동하는 실전 프로젝트 모음입니다.

## 📂 프로젝트 목록

### 0501_mysql - MySQL C++ Connector 기본
- **주제**: MySQL Connector/C++ 사용법
- **학습 내용**:
  - MySQL Connector 설정
  - 데이터베이스 연결
  - CRUD 작업 (Create, Read, Update, Delete)
  - PreparedStatement 사용
  - 결과 집합 처리

### 0502_server_socket - TCP 서버
- **주제**: 소켓 서버 구현
- **학습 내용**:
  - Winsock2 라이브러리 사용
  - 서버 소켓 생성 및 바인딩
  - 클라이언트 연결 수락
  - 데이터 송수신
  - 소켓 종료 처리

### 0502_socket_client - TCP 클라이언트
- **주제**: 소켓 클라이언트 구현
- **학습 내용**:
  - 클라이언트 소켓 생성
  - 서버 연결
  - 데이터 송수신
  - 연결 종료

### 0502_socket_server_sql - 소켓 서버 + MySQL
- **주제**: 네트워크 + 데이터베이스 통합
- **학습 내용**:
  - 클라이언트 요청 처리
  - MySQL 쿼리 실행
  - 결과를 클라이언트에 전송
  - 다중 클라이언트 처리

### 0502_socket_client_sql - 소켓 클라이언트 + MySQL
- **주제**: 클라이언트에서 DB 작업 요청
- **학습 내용**:
  - 서버에 쿼리 요청 전송
  - 결과 수신 및 출력

### 0502_thread - 멀티스레드
- **주제**: 멀티스레드 프로그래밍
- **학습 내용**:
  - `<thread>` 라이브러리
  - 스레드 생성 및 관리
  - 동기화 (mutex, lock_guard)
  - 스레드 안전성

## 🎯 핵심 개념

### 1. MySQL Connector/C++ 사용

#### 데이터베이스 연결
```cpp
#include <jdbc/mysql_driver.h>
#include <jdbc/mysql_connection.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/cppconn/prepared_statement.h>
#include <jdbc/cppconn/resultset.h>

using namespace std;
using namespace sql;

int main() {
    try {
        // 드라이버 로드
        mysql::MySQL_Driver* driver = mysql::get_mysql_driver_instance();

        // 데이터베이스 연결
        Connection* con = driver->connect("tcp://127.0.0.1:3306", "root", "password");

        // 데이터베이스 선택
        con->setSchema("testdb");

        cout << "데이터베이스 연결 성공!" << endl;

        // 연결 해제
        delete con;
    }
    catch (SQLException& e) {
        cout << "오류: " << e.what() << endl;
    }

    return 0;
}
```

#### SELECT 쿼리
```cpp
void selectData(Connection* con) {
    try {
        Statement* stmt = con->createStatement();
        ResultSet* res = stmt->executeQuery("SELECT id, name, age FROM users");

        while (res->next()) {
            int id = res->getInt("id");
            string name = res->getString("name");
            int age = res->getInt("age");

            cout << "ID: " << id
                 << ", Name: " << name
                 << ", Age: " << age << endl;
        }

        delete res;
        delete stmt;
    }
    catch (SQLException& e) {
        cout << "SELECT 오류: " << e.what() << endl;
    }
}
```

#### INSERT/UPDATE/DELETE
```cpp
void insertData(Connection* con, string name, int age) {
    try {
        // PreparedStatement 사용 (SQL Injection 방지)
        PreparedStatement* pstmt = con->prepareStatement(
            "INSERT INTO users (name, age) VALUES (?, ?)"
        );

        pstmt->setString(1, name);
        pstmt->setInt(2, age);

        int rows = pstmt->executeUpdate();
        cout << rows << "개 행 삽입됨" << endl;

        delete pstmt;
    }
    catch (SQLException& e) {
        cout << "INSERT 오류: " << e.what() << endl;
    }
}

void updateData(Connection* con, int id, int newAge) {
    try {
        PreparedStatement* pstmt = con->prepareStatement(
            "UPDATE users SET age = ? WHERE id = ?"
        );

        pstmt->setInt(1, newAge);
        pstmt->setInt(2, id);

        int rows = pstmt->executeUpdate();
        cout << rows << "개 행 수정됨" << endl;

        delete pstmt;
    }
    catch (SQLException& e) {
        cout << "UPDATE 오류: " << e.what() << endl;
    }
}

void deleteData(Connection* con, int id) {
    try {
        PreparedStatement* pstmt = con->prepareStatement(
            "DELETE FROM users WHERE id = ?"
        );

        pstmt->setInt(1, id);

        int rows = pstmt->executeUpdate();
        cout << rows << "개 행 삭제됨" << endl;

        delete pstmt;
    }
    catch (SQLException& e) {
        cout << "DELETE 오류: " << e.what() << endl;
    }
}
```

### 2. 소켓 프로그래밍

#### TCP 서버
```cpp
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main() {
    // Winsock 초기화
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cout << "WSAStartup 실패" << endl;
        return 1;
    }

    // 소켓 생성
    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        cout << "소켓 생성 실패" << endl;
        WSACleanup();
        return 1;
    }

    // 서버 주소 설정
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // 바인딩
    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        cout << "바인딩 실패" << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // 리스닝
    if (listen(serverSocket, 5) == SOCKET_ERROR) {
        cout << "리스닝 실패" << endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    cout << "서버 시작... 포트 8080에서 대기 중" << endl;

    // 클라이언트 연결 수락
    while (true) {
        sockaddr_in clientAddr;
        int clientAddrLen = sizeof(clientAddr);
        SOCKET clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientAddrLen);

        if (clientSocket == INVALID_SOCKET) {
            cout << "연결 수락 실패" << endl;
            continue;
        }

        cout << "클라이언트 연결됨!" << endl;

        // 데이터 수신
        char buffer[1024] = { 0 };
        int recvLen = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (recvLen > 0) {
            cout << "받은 메시지: " << buffer << endl;

            // 응답 전송
            string response = "메시지를 받았습니다!";
            send(clientSocket, response.c_str(), response.length(), 0);
        }

        // 클라이언트 소켓 종료
        closesocket(clientSocket);
    }

    // 서버 소켓 종료
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}
```

#### TCP 클라이언트
```cpp
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main() {
    // Winsock 초기화
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    // 소켓 생성
    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    // 서버 주소 설정
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

    // 서버 연결
    if (connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        cout << "서버 연결 실패" << endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    cout << "서버에 연결됨!" << endl;

    // 메시지 전송
    string message = "Hello Server!";
    send(clientSocket, message.c_str(), message.length(), 0);
    cout << "메시지 전송: " << message << endl;

    // 응답 수신
    char buffer[1024] = { 0 };
    int recvLen = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (recvLen > 0) {
        cout << "서버 응답: " << buffer << endl;
    }

    // 소켓 종료
    closesocket(clientSocket);
    WSACleanup();

    return 0;
}
```

### 3. 멀티스레드 프로그래밍

#### 기본 스레드
```cpp
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void printNumbers() {
    for (int i = 1; i <= 5; i++) {
        cout << "스레드: " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

int main() {
    // 스레드 생성
    thread t1(printNumbers);

    // 메인 스레드 작업
    for (int i = 1; i <= 5; i++) {
        cout << "메인: " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    // 스레드 종료 대기
    t1.join();

    return 0;
}
```

#### 동기화 (Mutex)
```cpp
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int counter = 0;
mutex mtx;

void increment() {
    for (int i = 0; i < 100000; i++) {
        lock_guard<mutex> lock(mtx);  // 자동 잠금/해제
        counter++;
    }
}

int main() {
    thread t1(increment);
    thread t2(increment);

    t1.join();
    t2.join();

    cout << "Counter: " << counter << endl;  // 200000

    return 0;
}
```

#### 다중 클라이언트 처리
```cpp
#include <thread>
#include <vector>

void handleClient(SOCKET clientSocket) {
    char buffer[1024] = { 0 };
    int recvLen = recv(clientSocket, buffer, sizeof(buffer), 0);

    if (recvLen > 0) {
        cout << "받은 메시지: " << buffer << endl;

        // 응답 전송
        send(clientSocket, buffer, recvLen, 0);
    }

    closesocket(clientSocket);
}

int main() {
    // ... 서버 소켓 설정 ...

    vector<thread> threads;

    while (true) {
        SOCKET clientSocket = accept(serverSocket, ...);

        if (clientSocket != INVALID_SOCKET) {
            // 각 클라이언트를 별도 스레드에서 처리
            threads.push_back(thread(handleClient, clientSocket));
        }
    }

    // 모든 스레드 종료 대기
    for (auto& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }

    return 0;
}
```

### 4. 소켓 서버 + MySQL 통합

```cpp
#include <winsock2.h>
#include <jdbc/mysql_driver.h>
#include <jdbc/mysql_connection.h>
#include <thread>

using namespace std;
using namespace sql;

Connection* getConnection() {
    mysql::MySQL_Driver* driver = mysql::get_mysql_driver_instance();
    Connection* con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
    con->setSchema("testdb");
    return con;
}

void handleClient(SOCKET clientSocket) {
    try {
        // 클라이언트 요청 수신
        char buffer[1024] = { 0 };
        recv(clientSocket, buffer, sizeof(buffer), 0);

        string query(buffer);
        cout << "요청 쿼리: " << query << endl;

        // MySQL 연결 및 쿼리 실행
        Connection* con = getConnection();
        Statement* stmt = con->createStatement();
        ResultSet* res = stmt->executeQuery(query);

        // 결과를 문자열로 변환
        string result = "";
        while (res->next()) {
            result += res->getString(1) + "\n";
        }

        // 클라이언트에 결과 전송
        send(clientSocket, result.c_str(), result.length(), 0);

        // 정리
        delete res;
        delete stmt;
        delete con;
    }
    catch (SQLException& e) {
        string error = "DB Error: " + string(e.what());
        send(clientSocket, error.c_str(), error.length(), 0);
    }

    closesocket(clientSocket);
}

int main() {
    // Winsock 및 서버 소켓 초기화
    // ...

    while (true) {
        SOCKET clientSocket = accept(serverSocket, ...);
        thread(handleClient, clientSocket).detach();
    }

    return 0;
}
```

## 📚 학습 순서

1. **0501_mysql**: MySQL Connector 기본 사용법
2. **0502_server_socket**: TCP 서버 구현
3. **0502_socket_client**: TCP 클라이언트 구현
4. **0502_thread**: 멀티스레드 개념
5. **0502_socket_server_sql**: 서버 + DB 통합
6. **0502_socket_client_sql**: 클라이언트에서 DB 작업 요청

## 💡 주요 학습 포인트

- ✅ MySQL Connector/C++ 설정 및 사용
- ✅ PreparedStatement로 SQL Injection 방지
- ✅ Winsock2로 소켓 프로그래밍
- ✅ TCP 서버/클라이언트 구조
- ✅ 멀티스레드로 동시 클라이언트 처리
- ✅ Mutex로 동기화 문제 해결
- ✅ 네트워크와 데이터베이스 통합

## 🛠 개발 환경 설정

### 1. MySQL Connector/C++ 설치
- 다운로드: `mysql-connector-c++-9.3.0-winx64`
- 위치: `external_libs/` 폴더

### 2. Visual Studio 프로젝트 설정

#### Include 디렉터리
```
external_libs/mysql-connector-c++-9.3.0-winx64/include
```

#### 라이브러리 디렉터리
```
external_libs/mysql-connector-c++-9.3.0-winx64/lib64/vs14
```

#### 추가 종속성
```
mysqlcppconn.lib
ws2_32.lib
```

### 3. DLL 파일 복사
프로젝트 실행 폴더에 필요한 DLL 복사:
- `libcrypto-3-x64.dll`
- `libssl-3-x64.dll`
- `mysqlcppconn-10-vs14.dll`
- `mysqlcppconnx-2-vs14.dll`

## 🚀 실전 프로젝트 아이디어

1. **채팅 서버**: 다중 클라이언트 채팅 + 메시지 DB 저장
2. **사용자 관리 시스템**: 로그인, 회원가입, 정보 수정
3. **게시판 시스템**: 글 작성, 조회, 수정, 삭제
4. **실시간 모니터링**: 센서 데이터 수집 및 저장
5. **API 서버**: RESTful API 스타일 구현

## 🔗 참고 자료

- [MySQL Connector/C++ 공식 문서](https://dev.mysql.com/doc/connector-cpp/8.0/en/)
- [Winsock2 공식 문서](https://docs.microsoft.com/en-us/windows/win32/winsock/)
- [C++ 스레드 라이브러리](https://en.cppreference.com/w/cpp/thread)
