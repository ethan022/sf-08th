#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <vector>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main()
{
	// 윈도우 소켓 초기화
	WSADATA wsaData;
	// 클라이언트 소켓
	SOCKET clientSocket;
	// 서버 주소 정보
	SOCKADDR_IN serverAddr;

	vector<char> buffer(1024);

	// 윈도우 소켓 초기화
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	// 클라이언트 소켓 생성
	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	// 클라이언트 소켓 생성 실패
	if (clientSocket == INVALID_SOCKET) {
		std::cerr << "Socket creation failed.\n";
		WSACleanup();
		return 1;
	}

	// 서버 주소 정보
	serverAddr.sin_family = AF_INET;
	// 포트 번호
	serverAddr.sin_port = htons(12345);
	// 서버 주소
	inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

	// 서버 연결
	if (connect(clientSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
		// 서버 연결 실패
		std::cerr << "Connection failed.\n";
		// 클라이언트 소켓 종료
		closesocket(clientSocket);
		// 윈도우 소켓 종료
		WSACleanup();
		return 1;
	}

	while (true) {
		cout << "Message:";
		// 사용자 입력
		cin.getline(buffer.data(), sizeof(buffer));

		// 종료 명령
		if (strcmp(buffer.data(), "exit") == 0) {
			break;
		}

		send(clientSocket, buffer.data(), strlen(buffer.data()), 0);

		int recvLen = recv(clientSocket, buffer.data(), sizeof(buffer), 0);
		cout << "Echo: " << buffer.data() << "\n";
	}

	// 클라이언트 소켓 종료
	closesocket(clientSocket);
	// 윈도우 소켓 종료
	WSACleanup();

	return 0;
}