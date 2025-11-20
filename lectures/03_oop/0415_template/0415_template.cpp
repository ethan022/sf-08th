

#include <iostream>

using namespace std;

template <typename T1, typename T2>

T2 add(T1 a, T2 b) {
    cout << "템플릿" << endl;
    return a + b;
}

double add(int a, double b) {
    cout << "일반 함수 " << endl;
    return a + b;
}


template <typename T>
class Box {
public:
    Box(T d) : data(d) {}
    ~Box() {}
protected:
    T data;



};

template <typename T>
class MyClass: public Box<T>
{
public:
    MyClass(T d) : Box<T>(d) {}
    ~MyClass() {}

    void show() {
        cout << "Data :" << this->data << endl;
    }
};

template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;

public:
    Pair(T1 f, T2 s) : first(f), second(s) {}
    ~Pair() {}

    void show() {
        cout << "First: " << first << ", Second: " << second << endl;
    }

    T1 getFrist() {
        return this->first;
    }
    T2 getSecond() {
        return this->second;
    }
    void setFrist(T1 f) {
        this->first = f;
    }
    void setSecond(T2 s) {
        this->second = s;
    }
};


int main()
{
    Pair<int, double> p1(42, 44.4);
    Pair<string, double> p2("aaa", 44.4);
    p1.show();
    p2.show();

    cout << p1.getFrist() << endl;
    cout << p1.getSecond() << endl;

    cout << p2.getFrist() << endl;
    cout << p2.getSecond() << endl;

    p1.setFrist(20);
    p1.setSecond(20.3);
    p2.setFrist("bbb");
    p2.setSecond(2.2);

    p1.show();
    p2.show();

    cout << add(2, 3.1) << endl;
    cout << add(2.2f, 3.1) << endl;

    MyClass<int> intBox(10);
    MyClass<double> doubleBox(10.1);
    MyClass<string> stringBox("10.11");

    intBox.show();
    doubleBox.show();
    stringBox.show();
}
