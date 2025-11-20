// 0409_class.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

class Car {
	// 비공개
	// 해당 클래스 내에서만 접근 가능하다.
//private:

	// 어디서나 접근 가능하다.
public:
	string brand;
	int speed;

	void display() {
		cout << "차량의 브랜드는 " << brand << "이고 속도는 " << speed << "km/h 입니다." << endl;
	}
};

class Point
{
	//클래스 내부에서만 접근이 가능하다.
private:
	int x;
	int y;

public:
	void setX(int x1) {
		x = x1;
	}
	void setY(int y1) {
		y = y1;
	}
	void print() {
		cout << x << ", " << y << endl;
	}
};

class Person {
private: 
	string name;
	int age;

public:
	void setName(string s) {
		name = s;
	}
	void setAge(int a) {
		age = a;
	}
	void showInfo() {
		cout << "이름 :" << name << " 나이 :" << age << endl;
	}
};

class Rect {
public: 
	Rect() {
		cout << "기본 생성자 호출됨!" << endl;
	}
	Rect(int w) {
		width = w;
		cout << "너비는 " << width << endl;
	}
	Rect(int w, int h) {
		width = w;
		height = h;
		cout << "너비는 " << width << "높이는 " << height << endl;
	}

	int width;
	int height;
};

class Book {
public: 
	string* title;

	Book(string t) {
		cout << "생성자 호출" << endl;
		title = &t;
	}
	Book(const Book& other) {
		title = new string(*other.title);
		cout << "복사 생성자가 호출되었습니다." << endl;
	}

	~Book() {
		cout << "소멸자 호출" << endl;
	}

};

class DynamicArray {
public:
	int* data;
	int size;

	DynamicArray(int s) {
		size = s;
		data = new int[size];
		cout << "동적 배열 생성 (크기:" << size << ")" << endl;
	}

	~DynamicArray() {
		delete[] data;
		cout << "동적 배열 해제" << endl;
	}
};

int main()
{

	DynamicArray d1(10);

	/*Book book1("c++");
	Book book2 = book1;*/

	//Rect rect1;
	//Rect rect2(10,20);
	//Rect rect3(20);

	//Car car1 = { "BMW", 200 };
	//car1.display()

	// 선언 
	//Point p1;
	//p1.setX(1);
	//p1.setY(2);
	//p1.print();

	//Person person1;
	//person1.setAge(10);
	//person1.setName("홍길동");
	//person1.showInfo();

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
