# 네트워크 프로그래밍 & MySQL 연동

## 📂 프로젝트 목록

### 0501_mysql - MySQL C++ Connector 기본
**학습 내용**:
- MySQL Connector/C++ 설정
- 데이터베이스 연결
- CRUD 작업 (Create, Read, Update, Delete)
- PreparedStatement 사용
- 결과 집합 처리

**주요 코드**:
```cpp
#include <jdbc/mysql_driver.h>
#include <jdbc/mysql_connection.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/cppconn/prepared_statement.h>
#include <jdbc/cppconn/resultset.h>

// 연결
mysql::MySQL_Driver* driver = mysql::get_mysql_driver_instance();
Connection* con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
con->setSchema("testdb");

// SELECT
Statement* stmt = con->createStatement();
ResultSet* res = stmt->executeQuery("SELECT * FROM users");
while (res->next()) {
    cout << res->getInt("id") << ", " << res->getString("name") << endl;
}

// INSERT (PreparedStatement)
PreparedStatement* pstmt = con->prepareStatement("INSERT INTO users (name, age) VALUES (?, ?)");
pstmt->setString(1, "Alice");
pstmt->setInt(2, 25);
pstmt->executeUpdate();

delete res;
delete stmt;
delete pstmt;
delete con;
```

---

### 0502_server_socket - TCP 서버
**학습 내용**:
- Winsock2 라이브러리 사용
- 서버 소켓 생성 및 바인딩
- 클라이언트 연결 수락
- 데이터 송수신
- 소켓 종료 처리

**주요 코드**:
```cpp
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

// Winsock 초기화
WSADATA wsaData;
WSAStartup(MAKEWORD(2, 2), &wsaData);

// 서버 소켓 생성
SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);

// 주소 설정 및 바인딩
sockaddr_in serverAddr;
serverAddr.sin_family = AF_INET;
serverAddr.sin_port = htons(8080);
serverAddr.sin_addr.s_addr = INADDR_ANY;
bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));

// 리스닝
listen(serverSocket, 5);

// 클라이언트 연결 수락
SOCKET clientSocket = accept(serverSocket, ...);

// 데이터 수신
char buffer[1024];
recv(clientSocket, buffer, sizeof(buffer), 0);

// 데이터 송신
send(clientSocket, "Hello", 5, 0);

// 종료
closesocket(clientSocket);
closesocket(serverSocket);
WSACleanup();
```

---

### 0502_socket_client - TCP 클라이언트
**학습 내용**:
- 클라이언트 소켓 생성
- 서버 연결
- 데이터 송수신

**주요 코드**:
```cpp
// 소켓 생성
SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);

// 서버 주소 설정
sockaddr_in serverAddr;
serverAddr.sin_family = AF_INET;
serverAddr.sin_port = htons(8080);
inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

// 서버 연결
connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));

// 메시지 전송
send(clientSocket, "Hello Server!", 13, 0);

// 응답 수신
char buffer[1024];
recv(clientSocket, buffer, sizeof(buffer), 0);

// 종료
closesocket(clientSocket);
```

---

### 0502_socket_server_sql - 소켓 서버 + MySQL 통합
**학습 내용**:
- 클라이언트 요청을 DB 쿼리로 처리
- 쿼리 결과를 클라이언트에 전송
- 다중 클라이언트 처리 (멀티스레드)

**주요 코드**:
```cpp
#include <thread>

Connection* getConnection() {
    mysql::MySQL_Driver* driver = mysql::get_mysql_driver_instance();
    Connection* con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
    con->setSchema("testdb");
    return con;
}

void handleClient(SOCKET clientSocket) {
    try {
        // 클라이언트 요청 수신
        char buffer[1024];
        recv(clientSocket, buffer, sizeof(buffer), 0);

        // MySQL 쿼리 실행
        Connection* con = getConnection();
        Statement* stmt = con->createStatement();
        ResultSet* res = stmt->executeQuery(buffer);

        // 결과를 문자열로 변환
        string result = "";
        while (res->next()) {
            result += res->getString(1) + "\n";
        }

        // 클라이언트에 전송
        send(clientSocket, result.c_str(), result.length(), 0);

        delete res;
        delete stmt;
        delete con;
    }
    catch (SQLException& e) {
        string error = "Error: " + string(e.what());
        send(clientSocket, error.c_str(), error.length(), 0);
    }

    closesocket(clientSocket);
}

int main() {
    // 서버 소켓 설정...

    while (true) {
        SOCKET clientSocket = accept(serverSocket, ...);
        thread(handleClient, clientSocket).detach();
    }
}
```

---

### 0502_socket_client_sql - 소켓 클라이언트 + MySQL
**학습 내용**:
- 서버에 SQL 쿼리 요청 전송
- 결과 수신 및 출력

**주요 코드**:
```cpp
// 서버 연결
connect(clientSocket, ...);

// SQL 쿼리 전송
string query = "SELECT * FROM users";
send(clientSocket, query.c_str(), query.length(), 0);

// 결과 수신
char buffer[4096];
recv(clientSocket, buffer, sizeof(buffer), 0);
cout << "결과:\n" << buffer << endl;
```

---

### 0502_thread - 멀티스레드 프로그래밍
**학습 내용**:
- `<thread>` 라이브러리
- 스레드 생성 및 관리
- 동기화 (mutex, lock_guard)
- 스레드 안전성

**주요 코드**:
```cpp
#include <thread>
#include <mutex>

mutex mtx;

void printNumbers(int id) {
    for (int i = 0; i < 5; i++) {
        lock_guard<mutex> lock(mtx);  // 자동 잠금/해제
        cout << "Thread " << id << ": " << i << endl;
    }
}

int main() {
    thread t1(printNumbers, 1);
    thread t2(printNumbers, 2);

    t1.join();  // t1 종료 대기
    t2.join();  // t2 종료 대기

    return 0;
}

// 공유 자원 보호
int counter = 0;
mutex mtx;

void increment() {
    for (int i = 0; i < 100000; i++) {
        lock_guard<mutex> lock(mtx);
        counter++;
    }
}
```

---

## 🎯 학습 목표

1. **MySQL 연동**: C++에서 데이터베이스 작업
2. **소켓 프로그래밍**: 네트워크 통신 구현
3. **멀티스레드**: 동시 처리 구현
4. **통합**: 서버-클라이언트-DB 시스템 구축

## 💡 핵심 개념

### 1. 소켓 통신 흐름

**서버**:
```
socket() → bind() → listen() → accept() → recv()/send() → close()
```

**클라이언트**:
```
socket() → connect() → send()/recv() → close()
```

### 2. MySQL Connector 작업 흐름

```
드라이버 획득 → 연결 → 쿼리 실행 → 결과 처리 → 리소스 해제
```

### 3. 멀티스레드 서버

```cpp
while (true) {
    SOCKET client = accept(...);
    thread(handleClient, client).detach();  // 각 클라이언트를 별도 스레드로
}
```

### 4. 동기화 필요성

```cpp
// 동기화 없음 - 문제 발생
counter++;  // 여러 스레드가 동시에 접근하면 데이터 손실

// 동기화 있음 - 안전
{
    lock_guard<mutex> lock(mtx);
    counter++;  // 한 번에 하나의 스레드만 접근
}
```

## 📋 개발 환경 설정

### 1. MySQL Connector/C++ 설치
```
external_libs/mysql-connector-c++-9.3.0-winx64/
```

### 2. Visual Studio 프로젝트 설정

**Include 디렉터리**:
```
external_libs/mysql-connector-c++-9.3.0-winx64/include
```

**라이브러리 디렉터리**:
```
external_libs/mysql-connector-c++-9.3.0-winx64/lib64/vs14
```

**추가 종속성**:
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

### 1. 채팅 서버
- 다중 클라이언트 동시 접속
- 메시지 브로드캐스팅
- 채팅 기록 DB 저장

### 2. 사용자 관리 시스템
- 회원가입, 로그인
- 사용자 정보 CRUD
- 세션 관리

### 3. 게시판 시스템
- 글 작성, 조회, 수정, 삭제
- 댓글 기능
- 조회수 카운팅

### 4. 실시간 데이터 수집
- 센서 데이터 수집
- DB 저장
- 통계 분석

## 📝 실습 순서

```
1. 0501_mysql → MySQL 기본 작업
2. 0502_server_socket, 0502_socket_client → 소켓 기초
3. 0502_thread → 멀티스레드 이해
4. 0502_socket_server_sql, 0502_socket_client_sql → 통합 시스템
```

## ⚠️ 주의사항

### 1. 메모리 관리
```cpp
Connection* con = driver->connect(...);
delete con;  // 반드시 해제!
```

### 2. SQL Injection 방지
```cpp
// 나쁜 예
string query = "SELECT * FROM users WHERE name = '" + name + "'";

// 좋은 예
PreparedStatement* pstmt = con->prepareStatement("SELECT * FROM users WHERE name = ?");
pstmt->setString(1, name);
```

### 3. 스레드 안전성
```cpp
// 공유 자원 접근 시 반드시 mutex 사용
lock_guard<mutex> lock(mtx);
sharedVariable++;
```

### 4. 소켓 종료
```cpp
closesocket(socket);  // 반드시 종료
WSACleanup();         // Winsock 정리
```

## 🔗 참고 자료

- [MySQL Connector/C++ 문서](https://dev.mysql.com/doc/connector-cpp/8.0/en/)
- [Winsock2 문서](https://docs.microsoft.com/en-us/windows/win32/winsock/)
- [C++ thread 문서](https://en.cppreference.com/w/cpp/thread)
