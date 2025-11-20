# C++ 자료구조 (STL 컨테이너)

## 📖 개요

C++ 표준 템플릿 라이브러리(STL)의 주요 컨테이너를 학습하는 프로젝트입니다.

## 📂 프로젝트 목록

### 0408_list - std::list
- **주제**: 이중 연결 리스트
- **학습 내용**:
  - `std::list` 기본 사용법
  - `push_back()`, `push_front()` - 요소 추가
  - `pop_back()`, `pop_front()` - 요소 제거
  - `begin()`, `end()` - 반복자
  - `insert()`, `erase()` - 삽입/삭제
  - `sort()`, `reverse()` - 정렬/역순

### 0408_vector - std::vector
- **주제**: 동적 배열
- **학습 내용**:
  - `std::vector` 기본 사용법
  - `push_back()`, `pop_back()` - 요소 추가/제거
  - `size()`, `capacity()` - 크기/용량
  - `at()`, `[]` - 요소 접근
  - `clear()`, `empty()` - 초기화/비어있는지 확인
  - `iterator` 사용법

## 🎯 핵심 개념

### 1. std::vector (동적 배열)
```cpp
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> nums;

    // 요소 추가
    nums.push_back(10);
    nums.push_back(20);
    nums.push_back(30);

    // 요소 접근
    cout << nums[0] << endl;        // 10
    cout << nums.at(1) << endl;     // 20

    // 크기 확인
    cout << "Size: " << nums.size() << endl;

    // 반복
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    // 범위 기반 for문
    for (int num : nums) {
        cout << num << " ";
    }

    return 0;
}
```

### 2. std::list (이중 연결 리스트)
```cpp
#include <list>
#include <iostream>
using namespace std;

int main() {
    list<int> nums;

    // 앞뒤로 추가
    nums.push_back(30);     // [30]
    nums.push_front(10);    // [10, 30]
    nums.push_back(40);     // [10, 30, 40]
    nums.push_front(5);     // [5, 10, 30, 40]

    // 정렬
    nums.sort();            // [5, 10, 30, 40]

    // 역순
    nums.reverse();         // [40, 30, 10, 5]

    // iterator를 사용한 순회
    for (list<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
        cout << *it << " ";
    }

    return 0;
}
```

## 📊 Vector vs List 비교

| 특징 | vector | list |
|------|--------|------|
| **내부 구조** | 연속된 메모리 (배열) | 노드 기반 (이중 연결) |
| **임의 접근** | O(1) - 빠름 | O(n) - 느림 |
| **삽입/삭제 (중간)** | O(n) - 느림 | O(1) - 빠름 |
| **삽입/삭제 (끝)** | O(1) | O(1) |
| **메모리** | 연속적, 효율적 | 불연속적, 포인터 오버헤드 |
| **사용 시기** | 임의 접근이 많을 때 | 삽입/삭제가 빈번할 때 |

## 💡 주요 학습 포인트

### Vector
- ✅ 동적 배열의 개념
- ✅ capacity와 size의 차이
- ✅ `[]` vs `at()`의 차이 (경계 검사)
- ✅ 반복자(iterator) 사용법
- ✅ 범위 기반 for문 활용

### List
- ✅ 이중 연결 리스트 구조
- ✅ push_front/push_back의 효율성
- ✅ 중간 삽입/삭제의 장점
- ✅ sort()와 reverse() 메서드
- ✅ iterator의 필요성

## 🔍 언제 무엇을 사용할까?

### Vector를 사용하는 경우
- 데이터를 순차적으로 읽기만 할 때
- 배열처럼 인덱스로 접근이 많을 때
- 메모리 효율이 중요할 때
- 끝에만 추가/삭제할 때

### List를 사용하는 경우
- 중간에 삽입/삭제가 빈번할 때
- 양쪽 끝에서 추가/삭제가 필요할 때
- 데이터 정렬이 자주 필요할 때
- 임의 접근이 필요 없을 때

## 🛠 실습 예제

### 학생 관리 시스템 (Vector)
```cpp
#include <vector>
#include <string>
using namespace std;

struct Student {
    string name;
    int score;
};

int main() {
    vector<Student> students;

    students.push_back({"Alice", 90});
    students.push_back({"Bob", 85});
    students.push_back({"Charlie", 95});

    // 모든 학생 출력
    for (const auto& student : students) {
        cout << student.name << ": " << student.score << endl;
    }

    return 0;
}
```

### 작업 큐 (List)
```cpp
#include <list>
#include <string>
using namespace std;

int main() {
    list<string> tasks;

    // 작업 추가
    tasks.push_back("Task 1");
    tasks.push_back("Task 2");
    tasks.push_front("Urgent Task");  // 긴급 작업을 앞에 추가

    // 작업 처리 (앞에서부터)
    while (!tasks.empty()) {
        cout << "Processing: " << tasks.front() << endl;
        tasks.pop_front();
    }

    return 0;
}
```

## 🔗 다음 단계

→ **03_oop**: 객체지향 프로그래밍으로 이동
