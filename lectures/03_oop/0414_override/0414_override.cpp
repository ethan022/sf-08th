

#include <iostream>
using namespace std;

class Animal {
public:
    virtual	void speak() {
		cout << "동물 소리를 냅니다." << endl;
	}
};

class Dog: public Animal {
public:
	Dog() {}
	~Dog() {}

	void speak() override {
		cout << "멍멍!" << endl;
	}
private:

};

class Cat : public Animal {
public:
	Cat() {}
	~Cat() {}

	void speak() override {
		cout << "야옹!" << endl;
	}
private:

};

class Vehicle {
public: 
	Vehicle(int s) : speed(s) {}
	~Vehicle() {}

	virtual void accelerate() {
	}
	virtual void show() {
		cout << "현재 속도: " << speed;
	}
protected:
	int speed;
	int acc;
};

class Car: public Vehicle {
public:
	Car(int s) : Vehicle(s) {}
	~Car() {}
	void accelerate() {
		speed += 20;
		cout << "시속 20km 증가"  << endl;
	}
};
class SportsCars : public Vehicle {
public:
	SportsCars(int s) : Vehicle(s) {}
	~SportsCars() {}
	void accelerate() {
		this->speed += 30;
		cout << "시속 30km 증가" << endl;
	}
};

class Truck : public Vehicle {
public:	
	Truck(int s) : Vehicle(s) {}
	~Truck() {}
	void accelerate() {
		speed += 10;
		cout << "시속 10km 증가" << endl;
	}
};


int main()
{
	int c;
	cout << "자동차 유형을 선택하세요 : \n1. Car(일반 자동차) \n2. SportsCar(스포츠카) \n3. Truck(트럭)" << endl;
	cin >> c;

	Vehicle* vPtr;

	if (c == 1) {
		vPtr = new Car(0);
	}
	else if (c == 2) {
		vPtr = new SportsCars(0);
	}
	else {
		vPtr = new Truck(0);
	}

	vPtr->accelerate();
	vPtr->show();


	//Dog d1;
	//d1.speak();

	//Animal a2 = d1;
	//a2.speak();

	//Animal a1;
	//a1.speak();

	////Animal* aPtr = new Dog();
	////aPtr->speak();

	////delete aPtr;

	//Animal* aPtr;
	//int choice;

	//cout << "1: Dog \n2: Cat\n";
	//cin >> choice;

	//if (choice == 1) {
	//	aPtr = new Dog();
	//}
	//else if (choice == 2) {
	//	aPtr = new Cat();
	//}
	//else {
	//	aPtr = new Animal();
	//}

	//aPtr->speak();
	//delete aPtr;


}
