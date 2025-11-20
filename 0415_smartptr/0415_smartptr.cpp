
#include <iostream>
#include <memory>
using namespace std;

class Test {
public:
	Test() { cout << "생성" << endl; }
	~Test() { cout << "소멸" << endl; }
};

shared_ptr<Test> createTest() {
	return make_shared<Test>();
}

class Base {
public:
	Base() {}
	~Base() {}

    virtual	void show() {
		cout << "Base 클래스" << endl;
	}
};

class Derived : public Base {
public:
	void show() override {
		cout << "Derived 클래스" << endl;
	}
};

int main()
{
	shared_ptr<Test> ptr1 = createTest();
	weak_ptr<Test> ptr2 = ptr1;

	//if (!ptr1) {
	//	cout << "더이상 객체를 소유하지 않습니다." << endl;
	//}
	if (auto locked = ptr2.lock()) {
		cout << "객체가 아직 존재합니다." << endl;
	} else {
		cout << "객체가 삭제 되었습니다." << endl;
	}

	cout << "참조 개수: " << ptr1.use_count() << endl;


	Derived d;
	Base* basePtr = &d; // 업캐스팅
	basePtr->show();

	Base* basePtr2 = new Derived(); // 업캐스팅
	//Derived* derivedPtr = (Derived*)basePtr2; // 강제적 다운 캐스팅
	Derived* derivedPtr = dynamic_cast<Derived*>(basePtr2);

	if (derivedPtr) {
		derivedPtr->show();
	}
	else {
		cout << "다운 캐스팅 실패";
	}

	delete basePtr2;


	shared_ptr<Derived> dervied = make_shared<Derived>();
	shared_ptr<Base> base = dervied;

	base->show();

	shared_ptr<Base> base2 = make_shared<Derived>();
	shared_ptr<Derived> derived2 = dynamic_pointer_cast<Derived>(base);//다운 캐스팅

	if (derived2) {
		derived2->show();
	}
	else {
		cout << "다운 캐스팅 실패" << endl;
	}


	//.\mysql - connector - c++ - 9.3.0 - winx64\include

	return 0;
}
