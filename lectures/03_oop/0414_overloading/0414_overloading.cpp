#include <iostream>

using namespace std;

class Math {
public:
	int add(int a, int b) { 
		cout << "1번 add 호출" << endl;
		return a + b; 
	}
	int add(int a, int b, int c) {
		cout << "2번 add 호출" << endl;
		return a + b + c;
	}
	double add(double a, double b) {
		cout << "3번 add 호출" << endl;
		return a + b;
	}
};

class Shape
{
public:
	// 정사각형의 면적
	int area(int side) {
		cout << "정사각형의 면적 : " << side * side << endl;
		return side * side;
	}
	// 직사각형의 면적
	int area(int width, int height) {
		cout << "직사각형의 면적 : " << width * height << endl;
		return width * height;
	}
	// 원의 면적
	double area(double radius) {
		cout << "원의 면적 : " << radius * radius * 3.14159 << endl;
		return radius * radius * 3.14159;
	}

};

class Weight
{
public:
	Weight(int w) : kg(w) {}
	~Weight() {}

	Weight operator+(const Weight& other) {
		return Weight(this->kg + other.kg);
	}

	Weight operator-(const Weight& other) {
		return Weight(this->kg - other.kg);
	}

	void show() {
		cout << "Weight: " << kg << "kg" << endl;
	}
private:
	int kg;
};

class Point {
public:
	Point(int x, int y) : x(x), y(y) {}
	~Point() {}

	Point operator+(Point& other) {
		return Point(this->x + other.x, this->y + other.y);
	}

	void show() {
		cout << "Point x: " << x << ", y:"<< y << endl;
	}
private: 
	int x;
	int y;


};


int main()
{
	Math m1;
	m1.add(1, 2);
	m1.add(1.2, 2.3);
	m1.add(1,2,3);

	Shape s1;
	s1.area(2);
	s1.area(2, 3);
	s1.area(3.1);

	Weight w1(50), w2(60);
	Weight w3 = w1 + w2;
	w3.show();
	Weight w4 = w2 - w1;
	w4.show();

	Point p1(2, 3), p2(3, 5);
	Point p3 = p1 + p2;
	p3.show();
}
