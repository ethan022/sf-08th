# 객체지향 프로그래밍 (OOP)

## 📖 개요

C++의 객체지향 프로그래밍 개념을 학습하는 프로젝트 모음입니다.

## 📂 프로젝트 목록

### 0409 - OOP 기초
- **주제**: 객체지향 개념 소개
- **학습 내용**: 클래스 vs 구조체, 객체 생성

### 0409_struct - 구조체
- **주제**: 구조체 기초
- **학습 내용**:
  - `struct` 정의 및 사용
  - 멤버 변수 접근
  - 구조체 배열

### 0409_class - 클래스 기초
- **주제**: 클래스 기본
- **학습 내용**:
  - 클래스 정의
  - 멤버 변수와 멤버 함수
  - 접근 지정자 (public, private, protected)
  - 생성자와 소멸자

### 0409_prac - 클래스 실습
- **주제**: 클래스 실전 연습
- **학습 내용**: 실제 프로그램에 클래스 적용

### 0410_class - 클래스 심화
- **주제**: 클래스 고급 개념
- **학습 내용**:
  - 복사 생성자
  - this 포인터
  - static 멤버
  - friend 함수

### 0410_prac - 심화 실습
- **주제**: 고급 클래스 개념 실습

### 0410_상속 - 상속
- **주제**: 상속의 개념
- **학습 내용**:
  - 기본 클래스와 파생 클래스
  - 상속 방식 (public, protected, private)
  - 생성자/소멸자 호출 순서
  - is-a 관계

### 0414_overloading - 오버로딩
- **주제**: 함수 오버로딩
- **학습 내용**:
  - 함수 오버로딩
  - 연산자 오버로딩
  - 생성자 오버로딩

### 0414_override - 오버라이드
- **주제**: 함수 재정의
- **학습 내용**:
  - 가상 함수 (virtual)
  - 함수 오버라이드
  - 동적 바인딩
  - 다형성

### 0414_추상클래스 - 추상 클래스
- **주제**: 추상 클래스와 인터페이스
- **학습 내용**:
  - 순수 가상 함수
  - 추상 클래스
  - 인터페이스 설계

### 0415_smartptr - 스마트 포인터
- **주제**: 메모리 자동 관리
- **학습 내용**:
  - `unique_ptr` - 독점 소유권
  - `shared_ptr` - 공유 소유권
  - `weak_ptr` - 약한 참조
  - RAII 패턴

### 0415_template - 템플릿
- **주제**: 제네릭 프로그래밍
- **학습 내용**:
  - 함수 템플릿
  - 클래스 템플릿
  - 템플릿 특수화

## 🎯 핵심 개념

### 1. 클래스와 객체
```cpp
class Person {
private:
    string name;
    int age;

public:
    // 생성자
    Person(string n, int a) : name(n), age(a) {}

    // 멤버 함수
    void introduce() {
        cout << "이름: " << name << ", 나이: " << age << endl;
    }

    // Getter
    string getName() const { return name; }

    // Setter
    void setAge(int a) { age = a; }
};

int main() {
    Person person("Alice", 25);
    person.introduce();
    return 0;
}
```

### 2. 상속
```cpp
// 기본 클래스
class Animal {
protected:
    string name;

public:
    Animal(string n) : name(n) {}

    virtual void speak() {
        cout << name << "이(가) 소리를 냅니다." << endl;
    }
};

// 파생 클래스
class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}

    void speak() override {
        cout << name << "이(가) 멍멍!" << endl;
    }
};

class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {}

    void speak() override {
        cout << name << "이(가) 야옹~" << endl;
    }
};
```

### 3. 다형성
```cpp
int main() {
    Animal* animals[2];
    animals[0] = new Dog("바둑이");
    animals[1] = new Cat("나비");

    for (int i = 0; i < 2; i++) {
        animals[i]->speak();  // 동적 바인딩
    }

    // 메모리 해제
    for (int i = 0; i < 2; i++) {
        delete animals[i];
    }

    return 0;
}
```

### 4. 추상 클래스
```cpp
// 추상 클래스 (인터페이스)
class Shape {
public:
    virtual double getArea() = 0;      // 순수 가상 함수
    virtual double getPerimeter() = 0;
    virtual ~Shape() {}                 // 가상 소멸자
};

// 구현 클래스
class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() override {
        return width * height;
    }

    double getPerimeter() override {
        return 2 * (width + height);
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getArea() override {
        return 3.14159 * radius * radius;
    }

    double getPerimeter() override {
        return 2 * 3.14159 * radius;
    }
};
```

### 5. 스마트 포인터
```cpp
#include <memory>

class Resource {
public:
    Resource() { cout << "Resource 생성" << endl; }
    ~Resource() { cout << "Resource 해제" << endl; }
    void use() { cout << "Resource 사용 중" << endl; }
};

int main() {
    // unique_ptr - 독점 소유권
    {
        unique_ptr<Resource> ptr1(new Resource());
        ptr1->use();
        // 자동으로 해제됨
    }

    // shared_ptr - 공유 소유권
    {
        shared_ptr<Resource> ptr1 = make_shared<Resource>();
        {
            shared_ptr<Resource> ptr2 = ptr1;  // 참조 카운트 증가
            cout << "참조 카운트: " << ptr1.use_count() << endl;  // 2
        }
        cout << "참조 카운트: " << ptr1.use_count() << endl;      // 1
        // 마지막 shared_ptr이 해제될 때 자동으로 메모리 해제
    }

    return 0;
}
```

### 6. 템플릿
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
    void push(T value) {
        data.push_back(value);
    }

    T pop() {
        T value = data.back();
        data.pop_back();
        return value;
    }

    bool isEmpty() {
        return data.empty();
    }
};

int main() {
    // 함수 템플릿 사용
    cout << getMax(10, 20) << endl;           // 20
    cout << getMax(3.14, 2.71) << endl;       // 3.14
    cout << getMax('a', 'z') << endl;         // z

    // 클래스 템플릿 사용
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    cout << intStack.pop() << endl;           // 20

    Stack<string> strStack;
    strStack.push("Hello");
    strStack.push("World");
    cout << strStack.pop() << endl;           // World

    return 0;
}
```

## 📚 OOP 4대 원칙

### 1. 캡슐화 (Encapsulation)
- 데이터와 메서드를 하나로 묶음
- 접근 제한을 통한 정보 은닉
- `private`, `public`, `protected` 사용

### 2. 상속 (Inheritance)
- 기존 클래스의 속성과 메서드를 재사용
- 코드 중복 감소
- is-a 관계 표현

### 3. 다형성 (Polymorphism)
- 같은 인터페이스로 다양한 구현
- 가상 함수와 오버라이드
- 동적 바인딩

### 4. 추상화 (Abstraction)
- 복잡한 구현을 숨기고 인터페이스만 제공
- 순수 가상 함수와 추상 클래스
- 인터페이스 설계

## 💡 주요 학습 포인트

- ✅ 클래스와 구조체의 차이
- ✅ 생성자/소멸자의 역할
- ✅ 접근 지정자의 중요성
- ✅ 상속과 다형성의 활용
- ✅ 가상 함수의 동작 원리
- ✅ 스마트 포인터로 메모리 관리
- ✅ 템플릿으로 재사용 가능한 코드 작성

## 🔗 다음 단계

→ **04_database**: SQL과 데이터베이스 학습으로 이동
