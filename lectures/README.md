# C++ 학습 프로젝트 모음

> C++ 기초부터 네트워크 프로그래밍까지 체계적으로 학습하는 프로젝트입니다.

## 📚 학습 카테고리

### [01_cpp_basics](./01_cpp_basics/) - C++ 기초 문법
**기간**: 2025.04.02 ~ 04.10 (9일)
**프로젝트**: 5개

**학습 주제**:
- ✅ 비트 연산자
- ✅ 조건문 (if, switch)
- ✅ 반복문 (for, while, do-while)
- ✅ 배열 (1차원, 2차원)
- ✅ 함수 (기본, 재귀)
- ✅ 포인터와 참조자
- ✅ 동적 메모리 할당
- ✅ 함수 포인터

**핵심 프로젝트**:
- `0402` - 기초 문법 종합 (비트 연산, 조건문, 반복문, 배열)
- `0403` - 함수와 모듈화 (재귀 함수, 헤더 파일 분리)
- `0407` - 포인터와 동적 메모리 (포인터, new/delete, 이중 포인터)

---

### [02_data_structures](./02_data_structures/) - STL 자료구조
**기간**: 2025.04.08 (1일)
**프로젝트**: 2개

**학습 주제**:
- ✅ `std::vector` - 동적 배열
- ✅ `std::list` - 이중 연결 리스트
- ✅ Iterator (반복자)
- ✅ 범위 기반 for문

**핵심 개념**:
- Vector: 빠른 인덱스 접근, 끝 추가/삭제 O(1)
- List: 양쪽 끝 추가/삭제 O(1), 중간 삽입/삭제 효율적
- 언제 무엇을 사용할지 판단 능력

---

### [03_oop](./03_oop/) - 객체지향 프로그래밍
**기간**: 2025.04.09 ~ 04.15 (7일)
**프로젝트**: 12개

**학습 주제**:
- ✅ 구조체와 클래스
- ✅ 접근 지정자 (public, private, protected)
- ✅ 생성자와 소멸자
- ✅ 상속 (Inheritance)
- ✅ 다형성 (Polymorphism)
- ✅ 함수 오버로딩 (Overloading)
- ✅ 함수 오버라이드 (Override)
- ✅ 가상 함수 (virtual)
- ✅ 추상 클래스와 순수 가상 함수
- ✅ 스마트 포인터 (unique_ptr, shared_ptr, weak_ptr)
- ✅ 템플릿 (Template)

**OOP 4대 원칙**:
1. **캡슐화** (Encapsulation) - private 멤버, getter/setter
2. **상속** (Inheritance) - 코드 재사용, is-a 관계
3. **다형성** (Polymorphism) - 가상 함수, 동적 바인딩
4. **추상화** (Abstraction) - 인터페이스, 순수 가상 함수

**핵심 프로젝트**:
- `0409_class` - 클래스 기초, 캡슐화
- `0410_상속` - 상속의 개념과 구현
- `0414_override` - 다형성과 가상 함수
- `0414_추상클래스` - 추상 클래스와 인터페이스
- `0415_smartptr` - 메모리 자동 관리
- `0415_template` - 제네릭 프로그래밍

---

### [04_database](./04_database/) - SQL & 데이터베이스
**기간**: 2025.04.30 (1일)
**SQL 파일**: 12개

**학습 주제**:
- ✅ 문자열 함수 (CONCAT, LENGTH, SUBSTRING, UPPER, LOWER)
- ✅ 숫자 함수 (ROUND, CEIL, FLOOR, ABS)
- ✅ 날짜 함수 (NOW, DATE_ADD, DATE_FORMAT, DATEDIFF)
- ✅ 조건 함수 (IF, CASE WHEN)
- ✅ 형 변환 (CAST, CONVERT)
- ✅ 서브쿼리 (WHERE, FROM, SELECT 절)
- ✅ 뷰 (View)
- ✅ 스토어드 프로시저 (IN, OUT 매개변수)
- ✅ 스토어드 함수

**핵심 파일**:
- `내장함수_기초(1,2).sql` - SQL 내장 함수
- `서브쿼리_기초.sql` - 복잡한 쿼리 작성
- `뷰_기초.sql` - 뷰로 쿼리 단순화
- `스토어드프로시져,함수_기초.sql` - 로직 캡슐화

---

### [05_network_mysql](./05_network_mysql/) - 네트워크 + MySQL 통합
**기간**: 2025.05.01 ~ 05.02 (2일)
**프로젝트**: 6개

**학습 주제**:
- ✅ MySQL Connector/C++ 사용법
- ✅ CRUD 작업 (Create, Read, Update, Delete)
- ✅ PreparedStatement (SQL Injection 방지)
- ✅ Winsock2 소켓 프로그래밍
- ✅ TCP 서버/클라이언트 구현
- ✅ 멀티스레드 (`<thread>`, `mutex`)
- ✅ 네트워크 + 데이터베이스 통합

**핵심 프로젝트**:
- `0501_mysql` - MySQL 기본 작업
- `0502_server_socket` - TCP 서버 구현
- `0502_socket_client` - TCP 클라이언트 구현
- `0502_thread` - 멀티스레드 프로그래밍
- `0502_socket_server_sql` - 서버 + DB 통합 (다중 클라이언트 처리)

---

## 🎯 전체 학습 로드맵

```
Week 1: C++ 기초
├─ Day 1-2: 비트 연산, 조건문, 반복문
├─ Day 3-4: 함수, 재귀
└─ Day 5-7: 포인터, 동적 메모리

Week 2: 자료구조 & OOP 기초
├─ Day 1: STL (vector, list)
├─ Day 2-3: 클래스, 캡슐화
└─ Day 4-5: 상속

Week 3: OOP 심화
├─ Day 1-2: 다형성, 가상 함수
├─ Day 3-4: 추상 클래스, 템플릿
└─ Day 5: 스마트 포인터

Week 4: 데이터베이스
└─ Day 1: SQL 종합

Week 5: 네트워크 & 통합
├─ Day 1: MySQL C++ 연동
└─ Day 2: 소켓 프로그래밍 + DB 통합
```

## 📊 학습 통계

| 카테고리 | 프로젝트/파일 수 | 소요 기간 | 난이도 |
|---------|----------------|----------|--------|
| **01_cpp_basics** | 5개 | 9일 | ⭐⭐ |
| **02_data_structures** | 2개 | 1일 | ⭐⭐ |
| **03_oop** | 12개 | 7일 | ⭐⭐⭐⭐ |
| **04_database** | 12개 | 1일 | ⭐⭐⭐ |
| **05_network_mysql** | 6개 | 2일 | ⭐⭐⭐⭐⭐ |
| **합계** | 37개 | 20일 | - |

## 💡 각 단계별 핵심 학습 포인트

### 🔰 초급 (01_cpp_basics)
- 기본 문법 익히기
- 포인터 개념 이해
- 메모리 관리 기초

### 🔸 중급 (02, 03_oop)
- STL 컨테이너 활용
- 객체지향 설계 원칙
- 다형성과 템플릿

### 🔶 고급 (04, 05_network_mysql)
- 데이터베이스 연동
- 네트워크 프로그래밍
- 멀티스레드 처리
- 실전 프로젝트 구현

## 📖 학습 방법

### 1. 순차 학습 (추천)
카테고리 순서대로 하나씩 완료
```
01 → 02 → 03 → 04 → 05
```

### 2. 병렬 학습
관련 있는 주제 동시 학습
```
C++ 문법 (01, 02, 03) + SQL (04)
이후 통합 프로젝트 (05)
```

### 3. 프로젝트 중심 학습
최종 목표(05) 먼저 보고 필요한 것만 학습
```
05 확인 → 필요한 부분 선택 학습
```

## 🚀 학습 완료 후 도전 과제

### 1. 미니 프로젝트
- [ ] 콘솔 기반 학생 관리 시스템
- [ ] 간단한 게임 (틱택토, 오목)
- [ ] 파일 I/O 기반 메모장

### 2. 실전 프로젝트
- [ ] 다중 사용자 채팅 서버
- [ ] RESTful API 서버 (HTTP)
- [ ] 실시간 데이터 수집 시스템

### 3. 오픈소스 기여
- [ ] GitHub에서 C++ 프로젝트 찾기
- [ ] 이슈 해결 또는 기능 추가
- [ ] 풀 리퀘스트 제출

## 📝 각 카테고리 상세 문서

각 폴더의 `README.md`에서 상세한 설명과 코드 예제를 확인하세요:

- [01_cpp_basics/README.md](./01_cpp_basics/README.md)
- [02_data_structures/README.md](./02_data_structures/README.md)
- [03_oop/README.md](./03_oop/README.md)
- [04_database/README.md](./04_database/README.md)
- [05_network_mysql/README.md](./05_network_mysql/README.md)

## ⚠️ 학습 시 주의사항

### 메모리 관리
```cpp
int* ptr = new int[10];
// ... 사용 ...
delete[] ptr;  // 반드시 해제!
```

### SQL Injection 방지
```cpp
// PreparedStatement 사용
pstmt->setString(1, userInput);  // 안전
```

### 스레드 안전성
```cpp
lock_guard<mutex> lock(mtx);
sharedData++;  // 보호된 접근
```

### 리소스 해제
```cpp
// 스마트 포인터 사용 권장
unique_ptr<MyClass> ptr = make_unique<MyClass>();
// 자동 해제됨!
```

## 🎓 학습 완료 체크리스트

- [ ] 01_cpp_basics - C++ 기초 문법 마스터
- [ ] 02_data_structures - STL 컨테이너 이해
- [ ] 03_oop - 객체지향 프로그래밍 완성
- [ ] 04_database - SQL 쿼리 작성 능력
- [ ] 05_network_mysql - 실전 프로젝트 구현

---

**Happy Coding! 🚀**

_"The best way to learn is by doing."_
