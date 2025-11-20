
#include <iostream>

using namespace std;

class Animal {
public:
	virtual void sound() = 0;
};

class Dog : public Animal {
	void sound() override {
		cout << "멍멍" << endl;
	}
};

class Cat : public Animal {
	void sound() override {
		cout << "야옹" << endl;
	}
};

class Snack {
public:
	Snack(string productName, string company, int price) :productName(productName), company(company), price(price) {}
	~Snack() {}
public:
	virtual void printInfo() = 0;

protected:
	string productName;
	string company;
	int price;
};

class Candy : public Snack {
public:
	Candy(string productName, string company, int price, string taste) :taste(taste), Snack(productName, company, price) {}
	~Candy() {}
public:
	void printInfo() {
		cout << "제품명: " << productName << ", 회사: " << company << ", 가격:" << price << ", 맛 :" << taste << endl;
	}
private:
	string taste;
};

class Chocolate : public Snack {
public:
	Chocolate(string productName, string company, int price, string shape):shape(shape), Snack(productName, company, price)  {}
	~Chocolate() {}
public:
	void printInfo() {
		cout << "제품명: " << productName << ", 회사: " << company << ", 가격:" << price << ", 모양 :" << shape << endl;
	}
private:
	string shape;
};

class Chatbot {
public: 
	virtual void respond(string message) = 0;
};

class CustomerSupportBot : public Chatbot {
public:
	void respond(string message) {
		cout << "고객 지원 문의를 처리합니다: " << message << endl;
	}
};

class WeatherBot : public Chatbot {
public:
	void respond(string message) {
		cout << "현재 날씨 정보를 제공합니다: " << message << endl;
	}
};

int main()
{
	Snack* snackBasket[4] = {
		new Chocolate("가나", "롯데", 800, "사각형"),
		new Candy("청포도", "롯데", 500, "청포도맛"),
		new Candy("사탕", "롯데", 800, "딸기맛"),
		new Chocolate("가나2", "롯데", 1000, "사각형"),
	};

	for (int i = 0; i < 4; i++)
	{
		snackBasket[i]->printInfo();
	}

	for (auto s : snackBasket) {
		delete s;
	}

	int c;

	while (true) {
		cout << "1. 고객 지원 봇 \n2. 날씨 봇 \n0. 종료";
		cin >> c;
		Chatbot* cPtr;

		if (c == 0) {
			break;
		}
		else if (c == 1) {
			cPtr = new CustomerSupportBot;
		}
		else {
			cPtr = new WeatherBot;
		}

		cPtr->respond("사용자");
		delete cPtr;
	}

}
