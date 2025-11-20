

#include <iostream>

using namespace std;

class Shape {
public:
	Shape(int s, int b): side(s), base(b) {}
	~Shape() {}

protected:
	// 변의 개수
	int side;
	// 밑변의 길이
	int base;

public:
	// 부모 멤버 함수
	void printInfo() {
		cout << "변의 개수 : " << side << ", 밑변의 길이: " << base << endl;
	}

};

class Triangle : public Shape {

public:
	Triangle(int h, int s, int b): height(h), Shape(s, b){}
	~Triangle() {}

private:
	int height;

public:
	void area() {
		cout << "삼각형의 너비는 :" << height * base / 2 << endl;
	}
};

class Rectangle : public Shape {
public:
	Rectangle(int v, int s, int b) : vertical(v), Shape(s, b) {}
	~Rectangle() {}
private:
	// 세로 길이
	int vertical;
public:

	void setVertical(int v) {
		this->vertical = v;
	}

	int getVertical() {
		return this->vertical;
	}

	void area() {
		cout << "사각형의 너비는 :" << vertical * base << endl;
	}
};

class Vehicle {
public:
	Vehicle(int s, string b): speed(s), brand(b)  {}
	~Vehicle() {}
protected:
	int speed;
	string brand;
public:
	void display() {
		cout << "브랜드 : " << brand << ", 속도 " << speed << "km/h 이다." << endl;
	}
};

class Car : public Vehicle {
public:
	Car(int n, int s, string b): num_person(n), Vehicle(s, b) {}
	~Car() {}
private:
	int num_person;

public:
	void display() {
		cout << "인원 :" << num_person << endl;
		Vehicle::display();
	}
};

class Truck : public Vehicle {
public:
	Truck(int c, int s, string b) : capacity(c), Vehicle(s, b) {}
	~Truck() {}
private:
	int capacity;

public:
	void display() {
		cout << "적재량 :" << capacity << endl;
		Vehicle::display();
	}
};


int main()
{
	//Triangle t1(10, 3, 10);
	//t1.area();
	//t1.printInfo();

	//Rectangle r1(20, 4, 10);
	//r1.area();
	//r1.printInfo();

	Car car1(4, 200, "BMW");
	car1.display();

	Truck truck1(10, 100, "현대");
	truck1.display();

}
