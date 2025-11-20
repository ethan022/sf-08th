#include <iostream>
#include <WinSock2.h>
#include <vector>
#include <string>

//#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main()
{
	// 윈도우 소켓 초기화
	WSADATA wsaData;
	// 서버 소켓, 클라이언트 소켓
	SOCKET serverSocket, clientSocket;
	// 서버 주소 정보, 클라이언트 주소 정보
	SOCKADDR_IN serverAddr, clientAddr;
	// 클라이언트 주소 정보 크기
	int clientSize = sizeof(clientAddr);
	// 버퍼
	vector<char> buffer(1024);

	// 윈도우 소켓 초기화
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	// 서버 소켓 생성
	serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	// 서버 소켓 생성 실패
	if (serverSocket == INVALID_SOCKET) {
		// 소켓 생성 실패
		std::cerr << "Socket creation failed.\n";
		// 윈도우 소켓 초기화 취소
		WSACleanup();
		return 1; 
	}

	// IPv4 
	serverAddr.sin_family = AF_INET;
	// 포트 번호
	serverAddr.sin_port = htons(12345);
	// 서버 주소
	serverAddr.sin_addr.s_addr = INADDR_ANY;

	// 서버 소켓 주소 바인딩
	if (bind(serverSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
		// 소켓 바인딩 실패
		std::cerr << "Socket bind failed.\n";
		// 서버 소켓 종료
		closesocket(serverSocket);
		// 윈도우 소켓 초기화 취소
		WSACleanup();
		return 1;
	}

	// 서버 소켓 연결 대기
	if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
		// 소켓 연결 대기 실패
		std::cerr << "Socket Listen failed.\n";
		// 서버 소켓 종료
		closesocket(serverSocket);
		// 윈도우 소켓 초기화 취소
		WSACleanup();
		return 1;
	}

	// 클라이언트 연결 대기
	clientSocket = accept(serverSocket, (SOCKADDR*)&clientAddr, &clientSize);
	// 클라이언트 연결 대기 실패
	if (clientSocket == INVALID_SOCKET) {
		// 서버 소켓 종료
		closesocket(serverSocket);
		// 윈도우 소켓 초기화 취소
		WSACleanup();
		return 1;
	}

	// 데이터 수신
	int recvLen;
	// 데이터 수신 대기
	while ((recvLen = recv(clientSocket, buffer.data(), buffer.size(), 0)) > 0) {
		// 데이터 수신
		cout << "Received: " << string(buffer.data(), recvLen) << "\n";
		// 데이터 송신
		send(clientSocket, buffer.data(), recvLen, 0);
	}

	// 서버 소켓 종료
	closesocket(serverSocket);
	// 윈도우 소켓 종료
	WSACleanup();

	return 0;
}

