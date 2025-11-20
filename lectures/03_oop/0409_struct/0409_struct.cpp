// 0409_struct.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;


struct Tire
{
	string brand;
	int size;

	void display() {
		cout << "타이어 브랜드는 " << brand << " 사이즈는 " << size << "이다" << endl;
	}
};

struct Car
{
	// 멤버 변수
	string brand;
	int speed;
	Tire tire;

	void accelerate() {
		speed += 10;
	}

	void display() {
		cout << "자동차 브랜드는 " << brand << "이고 속도는 " << speed << "km/h 이다." << endl;
		tire.display();
	}
};

struct Rectangle
{
	int width;
	int height;
};


struct Point
{
	// 멤버 변수
	int x;
	int y;

	// 멤버 함수
	void add(const Point p) {
		x += p.x;
		y += p.y;
	}
};

int main()
{
	Car myCar = { "tesla", 100, {"금호", 17}};

	cout << myCar.brand << endl;
	cout << myCar.tire.size << endl;

	myCar.display();
	myCar.accelerate();
	myCar.display();

	Car* ptr = &myCar;
	cout << "차량의 브랜드는 " << ptr->brand << endl;
	cout << "타이어의 브랜드는 " << ptr->tire.brand << endl;

	Rectangle rect;
	cout << "사각형의 너비를 입력하세요" << endl;
	cin >> rect.width;
	cout << "사각형의 높이를 입력하세요" << endl;
	cin >> rect.height;
	cout << "사각형의 너비는 " << rect.width << "이고 높이는 " << rect.height << "이다." << endl;

	cout << "사각형의 넓이는 " << rect.width * rect.height << "이다." << endl;

	cout << "좌표를 입력하세요" << endl;
	// 선언
	Point p1;
	cin >> p1.x >> p1.y;
	cout << "좌표를 입력하세요" << endl;
	// 선언
	Point p2;
	cin >> p2.x >> p2.y;
	p1.add(p2);
	cout << "p1의 좌표는 " << p1.x << ", " << p1.y << "이다." << endl;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
