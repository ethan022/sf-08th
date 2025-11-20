# 객체지향 프로그래밍 (OOP)

## 📂 프로젝트 목록

### 0409 - OOP 기초
**학습 내용**: 객체지향 개념 소개

### 0409_struct - 구조체
**학습 내용**:
- `struct` 정의 및 사용
- 멤버 변수 접근
- 구조체 vs 클래스 차이

```cpp
struct Student {
    string name;
    int age;
    double score;
};

Student s1 = {"Alice", 20, 95.5};
cout << s1.name;
```

---

### 0409_class - 클래스 기초
**학습 내용**:
- 클래스 정의
- 접근 지정자: `public`, `private`, `protected`
- Getter/Setter 메서드
- 멤버 함수

```cpp
class Car {
public:
    string brand;
    int speed;

    void display() {
        cout << brand << ": " << speed << "km/h" << endl;
    }
};

class Point {
private:
    int x, y;

public:
    void setX(int x1) { x = x1; }
    void setY(int y1) { y = y1; }
    void print() { cout << x << ", " << y << endl; }
};
```

---

### 0409_prac - 클래스 실습
**학습 내용**: 클래스 기초 실전 연습

---

### 0410_class - 클래스 심화
**학습 내용**:
- 생성자와 소멸자
- 복사 생성자
- `this` 포인터
- `static` 멤버
- `friend` 함수

```cpp
class MyClass {
private:
    int value;
    static int count;  // 모든 객체가 공유

public:
    MyClass(int v) : value(v) { count++; }
    ~MyClass() { count--; }

    MyClass(const MyClass& other) {  // 복사 생성자
        value = other.value;
    }

    void setValue(int v) {
        this->value = v;  // this 포인터
    }

    static int getCount() { return count; }
};
```

---

### 0410_prac - 심화 실습
**학습 내용**: 생성자, static, this 포인터 실습

---

### 0410_상속 - 상속
**학습 내용**:
- 기본 클래스와 파생 클래스
- 상속 방식: `public`, `protected`, `private`
- 생성자/소멸자 호출 순서
- is-a 관계

```cpp
class Animal {
protected:
    string name;

public:
    Animal(string n) : name(n) {}

    void eat() {
        cout << name << " is eating" << endl;
    }
};

class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}

    void bark() {
        cout << name << " is barking" << endl;
    }
};
```

---

### 0414_overloading - 오버로딩
**학습 내용**:
- 함수 오버로딩
- 연산자 오버로딩
- 생성자 오버로딩

```cpp
class Calculator {
public:
    // 함수 오버로딩
    int add(int a, int b) { return a + b; }
    double add(double a, double b) { return a + b; }
    int add(int a, int b, int c) { return a + b + c; }
};

class Point {
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // 연산자 오버로딩
    Point operator+(const Point& p) {
        return Point(x + p.x, y + p.y);
    }
};
```

---

### 0414_override - 오버라이드
**학습 내용**:
- 가상 함수 (`virtual`)
- 함수 오버라이드
- 다형성 (Polymorphism)
- 동적 바인딩

```cpp
class Shape {
public:
    virtual double getArea() = 0;  // 순수 가상 함수
    virtual ~Shape() {}
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}

    double getArea() override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() override {
        return width * height;
    }
};

// 다형성 활용
Shape* shapes[2];
shapes[0] = new Circle(5);
shapes[1] = new Rectangle(3, 4);

for (int i = 0; i < 2; i++) {
    cout << shapes[i]->getArea() << endl;
}
```

---

### 0414_추상클래스 - 추상 클래스
**학습 내용**:
- 순수 가상 함수 (`= 0`)
- 추상 클래스 (인스턴스 생성 불가)
- 인터페이스 설계

```cpp
class IDrawable {
public:
    virtual void draw() = 0;
    virtual ~IDrawable() {}
};

class IMovable {
public:
    virtual void move(int x, int y) = 0;
    virtual ~IMovable() {}
};

class GameObject : public IDrawable, public IMovable {
public:
    void draw() override {
        cout << "Drawing..." << endl;
    }

    void move(int x, int y) override {
        cout << "Moving to (" << x << ", " << y << ")" << endl;
    }
};
```

---

### 0415_smartptr - 스마트 포인터
**학습 내용**:
- `unique_ptr` - 독점 소유권
- `shared_ptr` - 공유 소유권
- `weak_ptr` - 약한 참조
- RAII 패턴

```cpp
#include <memory>

// unique_ptr - 하나만 소유
unique_ptr<int> ptr1(new int(10));
unique_ptr<int> ptr2 = make_unique<int>(20);
// unique_ptr<int> ptr3 = ptr1;  // 에러! 복사 불가
unique_ptr<int> ptr3 = move(ptr1);  // 소유권 이전

// shared_ptr - 여러 개가 공유
shared_ptr<int> sp1 = make_shared<int>(30);
shared_ptr<int> sp2 = sp1;  // 참조 카운트 증가
cout << sp1.use_count() << endl;  // 2

// weak_ptr - 순환 참조 방지
weak_ptr<int> wp = sp1;
```

---

### 0415_template - 템플릿
**학습 내용**:
- 함수 템플릿
- 클래스 템플릿
- 템플릿 특수화

```cpp
// 함수 템플릿
template <typename T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

// 클래스 템플릿
template <typename T>
class Stack {
private:
    vector<T> data;

public:
    void push(T value) { data.push_back(value); }
    T pop() {
        T value = data.back();
        data.pop_back();
        return value;
    }
    bool isEmpty() { return data.empty(); }
};

// 사용
Stack<int> intStack;
intStack.push(10);

Stack<string> strStack;
strStack.push("Hello");
```

---

## 🎯 OOP 4대 원칙

### 1. 캡슐화 (Encapsulation)
데이터와 메서드를 하나로 묶고 외부 접근을 제한
```cpp
class BankAccount {
private:
    double balance;  // 외부에서 직접 접근 불가
public:
    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }
    double getBalance() { return balance; }
};
```

### 2. 상속 (Inheritance)
기존 클래스의 속성과 메서드를 재사용
```cpp
class Vehicle { };
class Car : public Vehicle { };  // Car는 Vehicle의 모든 것을 상속
```

### 3. 다형성 (Polymorphism)
같은 인터페이스로 다양한 구현
```cpp
Shape* shape = new Circle(5);
shape->getArea();  // Circle의 getArea() 호출
```

### 4. 추상화 (Abstraction)
복잡한 구현을 숨기고 인터페이스만 제공
```cpp
class IDatabase {
public:
    virtual void connect() = 0;
    virtual void query(string sql) = 0;
};
```

## 💡 핵심 개념

### Overloading vs Override

| 구분 | Overloading | Override |
|------|-------------|----------|
| **의미** | 같은 이름, 다른 매개변수 | 부모 함수 재정의 |
| **위치** | 같은 클래스 내 | 상속 관계 |
| **키워드** | 없음 | `virtual`, `override` |
| **바인딩** | 컴파일 타임 | 런타임 |

### 스마트 포인터 선택 가이드

- **unique_ptr**: 독점 소유, 가볍고 빠름
- **shared_ptr**: 공유 소유, 참조 카운팅
- **weak_ptr**: shared_ptr의 순환 참조 방지

## 📝 학습 순서

```
struct → class → 상속 → overloading → override → 추상클래스 → 스마트포인터 → 템플릿
```

## 🚀 실습 과제

1. **도형 클래스 계층 구조 만들기**
   - Shape 추상 클래스
   - Circle, Rectangle, Triangle 파생 클래스
   - 다형성 활용

2. **스마트 포인터로 메모리 관리**
   - unique_ptr로 단독 소유 자원 관리
   - shared_ptr로 공유 자원 관리

3. **템플릿 컨테이너 구현**
   - Stack, Queue 클래스 템플릿 만들기
