// 0410_class.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

class Point {
public:
    int x;
    int y;

    //
    Point() {
        this->x = 0;
        this->y = 0;
    }
    // 생성자
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    // 소멸자
    ~Point() {

    }

    Point* setPoint(int x, int y) {
        this->x = x;
        this->y = y;

        return this;
    }

    void show() {
        cout << "x :" << this->x << ", y :" << this->y << endl;
    }
};

class Rectangle {
public:
    Rectangle(int w, int h) {
        this->width = w;
        this->height = h;
    }

    ~Rectangle() {

    }

    int width;
    int height;

    int getArea() {
        return this->width * this->height;
    }

    Rectangle* compareArea(Rectangle& other) {
        if (this->getArea() > other.getArea()) {
            return this;
        }
        else {
            return &other;
        }
    }

};

class Counter {
private:
    static int count;

public:
    Counter() {
        count++;
    }

    ~Counter() {
        count--;
    }

    static int getCount() {
        return count;
    }
};

int Counter::count = 0;


class User {
private:
    static int nextID;
    static int count;

public:
    int id;
    string name;

    User(string name) {
        this->name = name;
        this->id = nextID;
        nextID++;
        count++;
    }

    ~User() {
        count--;
    }

    static int getTotalUsers() {
        return  count;
    }

    void showInfo() {
        cout <<"아이디는 :"<< this->id << ", 이름은 " << this->name << endl;
    }

};

int User::nextID = 1;
int User::count = 0;

class Car {
public:
    Car(string brand) {
        this->brand = brand;
    }
    ~Car() {

    }
    // 접근 불가능
    // 클래스 내부에서만 접근이 가능
private:
    string brand;

public:
    void setBrand(string brand) {
        this->brand = brand;
    }

    void showBrand() const {
        //this->brand = "변경";
        cout << "브랜드는 : " << this->brand << endl;
    }
};


int main()
{
    Car car1("KIA");
    car1.showBrand();
    car1.setBrand("BMW");
    car1.showBrand();

    const Car car2("현대");
    //car2.setBrand("BMW");
    car2.showBrand();


    User user1("홍길동");
    user1.showInfo();
    User user2("ethan");
    user2.showInfo();

    User* uPtr1 = new User("uPtr1");
    cout << "uPtr1";
    uPtr1->showInfo();
    User* uPtr2 = new User("uPtr2");
    cout << "uPtr2";
    uPtr2->showInfo();

    cout << "객체 수: " << User::getTotalUsers() << endl;

    delete uPtr1;

    User* uPtr3 = new User("uPtr3");
    cout << "uPtr3";
    uPtr3->showInfo();
    cout << "객체 수: " << User::getTotalUsers() << endl;


    delete uPtr2;
    delete uPtr3;
    cout << "객체 수: " << User::getTotalUsers() << endl;




    Point p1;
    Point p2(10, 20);

    p1.show();
    p2.show();

    p1.setPoint(20, 20)->show();
    p2.setPoint(30, 30)->show();

    Point* pPtr = new Point();
    pPtr->setPoint(10, 10)->show();

    delete pPtr;

    Rectangle rect1(20, 10);
    Rectangle rect2(15, 15);

    cout << "더큰 사각형 너비는 : " << rect1.compareArea(rect2)->getArea() << endl;

    Counter c1, c2, c3;
    cout << "객체 수 :" << Counter::getCount() << endl;

    Counter* cPtr = new Counter;
    cout << "객체 수 :" << Counter::getCount() << endl;

    delete cPtr;
    cout << "객체 수 :" << Counter::getCount() << endl;
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
