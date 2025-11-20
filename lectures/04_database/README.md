# SQL & 데이터베이스

## 📂 SQL 파일 목록

위치: `04_database/0430/`

### 1. 내장 함수

#### 내장함수_db.sql
데이터베이스 및 테스트 데이터 생성

#### 내장함수_기초(1).sql
**학습 내용**:
- 문자열 함수: `CONCAT`, `LENGTH`, `SUBSTRING`, `UPPER`, `LOWER`
- 숫자 함수: `ROUND`, `CEIL`, `FLOOR`, `ABS`
- 날짜 함수: `NOW`, `CURDATE`, `YEAR`, `MONTH`, `DAY`

```sql
-- 문자열 함수
SELECT CONCAT('Hello', ' ', 'World');           -- 'Hello World'
SELECT LENGTH('Hello');                         -- 5
SELECT SUBSTRING('Hello World', 1, 5);          -- 'Hello'
SELECT UPPER('hello'), LOWER('WORLD');          -- 'HELLO', 'world'

-- 숫자 함수
SELECT ROUND(3.14159, 2);                       -- 3.14
SELECT CEIL(3.14), FLOOR(3.99);                 -- 4, 3
SELECT ABS(-10);                                -- 10

-- 날짜 함수
SELECT NOW();                                    -- 현재 날짜시간
SELECT CURDATE(), CURTIME();                    -- 현재 날짜, 현재 시간
SELECT YEAR(NOW()), MONTH(NOW()), DAY(NOW());  -- 연, 월, 일
```

#### 내장함수_기초(2).sql
**학습 내용**:
- 날짜 연산: `DATE_ADD`, `DATE_SUB`, `DATEDIFF`
- 날짜 포맷: `DATE_FORMAT`
- 조건 함수: `IF`, `CASE WHEN`
- NULL 처리: `IFNULL`, `COALESCE`

```sql
-- 날짜 연산
SELECT DATE_ADD(NOW(), INTERVAL 7 DAY);         -- 7일 후
SELECT DATE_SUB(NOW(), INTERVAL 1 MONTH);       -- 1개월 전
SELECT DATEDIFF('2025-12-31', NOW());           -- 남은 일수

-- 날짜 포맷
SELECT DATE_FORMAT(NOW(), '%Y년 %m월 %d일');    -- 2025년 01월 19일
SELECT DATE_FORMAT(NOW(), '%H:%i:%s');          -- 16:30:00

-- 조건 함수
SELECT IF(score >= 60, '합격', '불합격');
SELECT
    CASE
        WHEN score >= 90 THEN 'A'
        WHEN score >= 80 THEN 'B'
        WHEN score >= 70 THEN 'C'
        ELSE 'F'
    END AS grade;

-- NULL 처리
SELECT IFNULL(phone, '번호 없음');
SELECT COALESCE(mobile, phone, email);          -- 첫 번째 NOT NULL 값
```

#### 내장함수_형변환.sql
**학습 내용**:
- 데이터 타입 변환: `CAST`, `CONVERT`
- 문자열 → 숫자, 날짜 변환

```sql
-- 형 변환
SELECT CAST('123' AS SIGNED);                   -- 문자열 → 정수
SELECT CAST(123 AS CHAR);                       -- 숫자 → 문자열
SELECT CAST('2025-01-19' AS DATE);              -- 문자열 → 날짜

SELECT CONVERT('123', SIGNED);
SELECT STR_TO_DATE('2025/01/19', '%Y/%m/%d');  -- 형식 지정 변환
```

#### 내장함수_실습1.sql, 실습2.sql, 실습3.sql
내장 함수 실습 문제

---

### 2. 서브쿼리

#### 서브쿼리_기초.sql
**학습 내용**:
- WHERE 절 서브쿼리
- FROM 절 서브쿼리 (인라인 뷰)
- SELECT 절 서브쿼리 (스칼라 서브쿼리)
- EXISTS, IN, ANY, ALL

```sql
-- WHERE 절 서브쿼리
SELECT name, salary
FROM employees
WHERE salary > (SELECT AVG(salary) FROM employees);

-- IN 서브쿼리
SELECT name
FROM employees
WHERE dept_id IN (
    SELECT id FROM departments WHERE location = 'Seoul'
);

-- EXISTS 서브쿼리
SELECT name
FROM customers c
WHERE EXISTS (
    SELECT 1 FROM orders o WHERE o.customer_id = c.id
);

-- FROM 절 서브쿼리 (인라인 뷰)
SELECT dept_name, avg_salary
FROM (
    SELECT dept_id, AVG(salary) AS avg_salary
    FROM employees
    GROUP BY dept_id
) AS dept_avg
JOIN departments ON dept_avg.dept_id = departments.id;

-- SELECT 절 서브쿼리 (스칼라)
SELECT
    name,
    salary,
    (SELECT AVG(salary) FROM employees) AS avg_salary
FROM employees;
```

#### 서브쿼리_실습1.sql
서브쿼리 실습 문제

---

### 3. 뷰 (View)

#### 뷰_기초.sql
**학습 내용**:
- 뷰 생성: `CREATE VIEW`
- 뷰 조회
- 뷰 수정: `CREATE OR REPLACE VIEW`
- 뷰 삭제: `DROP VIEW`

```sql
-- 뷰 생성
CREATE VIEW high_salary_employees AS
SELECT name, department, salary
FROM employees
WHERE salary > 5000000;

-- 복잡한 조인을 뷰로
CREATE VIEW dept_summary AS
SELECT
    d.name AS dept_name,
    COUNT(e.id) AS emp_count,
    AVG(e.salary) AS avg_salary
FROM departments d
LEFT JOIN employees e ON d.id = e.dept_id
GROUP BY d.id, d.name;

-- 뷰 사용 (일반 테이블처럼)
SELECT * FROM high_salary_employees;
SELECT * FROM dept_summary WHERE emp_count > 10;

-- 뷰 수정
CREATE OR REPLACE VIEW high_salary_employees AS
SELECT name, department, salary, hire_date
FROM employees
WHERE salary > 6000000;

-- 뷰 삭제
DROP VIEW IF EXISTS high_salary_employees;
```

#### 뷰_실습2.sql
뷰 실습 문제

---

### 4. 스토어드 프로시저 & 함수

#### 스토어드프로시져,함수_기초.sql
**학습 내용**:
- 스토어드 프로시저 생성 및 호출
- 매개변수: IN, OUT, INOUT
- 스토어드 함수 생성
- 변수 선언 및 사용

```sql
-- 기본 프로시저
DELIMITER //
CREATE PROCEDURE GetEmployeeCount()
BEGIN
    SELECT COUNT(*) AS total FROM employees;
END //
DELIMITER ;

CALL GetEmployeeCount();

-- IN 매개변수
DELIMITER //
CREATE PROCEDURE GetEmployeesByDept(IN dept_name VARCHAR(50))
BEGIN
    SELECT name, salary
    FROM employees
    WHERE department = dept_name;
END //
DELIMITER ;

CALL GetEmployeesByDept('개발팀');

-- OUT 매개변수
DELIMITER //
CREATE PROCEDURE GetSalaryStats(
    IN dept_name VARCHAR(50),
    OUT avg_sal DECIMAL(10,2),
    OUT max_sal DECIMAL(10,2)
)
BEGIN
    SELECT AVG(salary), MAX(salary)
    INTO avg_sal, max_sal
    FROM employees
    WHERE department = dept_name;
END //
DELIMITER ;

CALL GetSalaryStats('개발팀', @avg, @max);
SELECT @avg, @max;

-- 스토어드 함수
DELIMITER //
CREATE FUNCTION CalculateBonus(salary DECIMAL(10,2))
RETURNS DECIMAL(10,2)
DETERMINISTIC
BEGIN
    DECLARE bonus DECIMAL(10,2);

    IF salary >= 5000000 THEN
        SET bonus = salary * 0.15;
    ELSE
        SET bonus = salary * 0.10;
    END IF;

    RETURN bonus;
END //
DELIMITER ;

-- 함수 사용
SELECT name, salary, CalculateBonus(salary) AS bonus
FROM employees;
```

---

## 🎯 학습 목표

1. **내장 함수 마스터**: 문자열, 숫자, 날짜 함수 활용
2. **서브쿼리 이해**: 복잡한 조건과 데이터 조회
3. **뷰 활용**: 복잡한 쿼리 단순화
4. **프로시저/함수**: 로직 캡슐화

## 💡 핵심 개념

### 서브쿼리 종류

| 위치 | 이름 | 특징 | 예시 |
|------|------|------|------|
| WHERE | 중첩 서브쿼리 | 조건 비교 | `WHERE salary > (SELECT AVG...)` |
| FROM | 인라인 뷰 | 임시 테이블 | `FROM (SELECT ...) AS tmp` |
| SELECT | 스칼라 서브쿼리 | 단일 값 반환 | `SELECT name, (SELECT AVG...)` |

### 뷰 vs 테이블

| 구분 | 뷰 | 테이블 |
|------|-------|--------|
| **저장** | 쿼리만 저장 | 실제 데이터 저장 |
| **성능** | 매번 쿼리 실행 | 빠름 |
| **업데이트** | 제한적 | 자유로움 |
| **용도** | 복잡한 쿼리 단순화 | 데이터 저장 |

### 프로시저 vs 함수

| 구분 | 프로시저 | 함수 |
|------|----------|------|
| **반환** | OUT 매개변수 | RETURN 값 |
| **호출** | `CALL` | SELECT 문에서 사용 |
| **용도** | 작업 수행 | 값 계산 |

## 📝 실습 순서

1. **내장함수_기초(1,2)** → 기본 함수 익히기
2. **내장함수_실습** → 문제 풀이
3. **서브쿼리_기초** → 서브쿼리 이해
4. **뷰_기초** → 뷰 생성 및 활용
5. **스토어드프로시져** → 로직 구현

## 🚀 실전 활용

### 월별 매출 분석
```sql
SELECT
    DATE_FORMAT(order_date, '%Y-%m') AS month,
    COUNT(*) AS order_count,
    SUM(total_amount) AS monthly_sales,
    AVG(total_amount) AS avg_order_value
FROM orders
WHERE order_date >= DATE_SUB(NOW(), INTERVAL 12 MONTH)
GROUP BY DATE_FORMAT(order_date, '%Y-%m')
ORDER BY month;
```

### 부서별 급여 통계
```sql
SELECT
    d.name AS department,
    COUNT(e.id) AS emp_count,
    AVG(e.salary) AS avg_salary,
    MAX(e.salary) AS max_salary,
    MIN(e.salary) AS min_salary
FROM departments d
LEFT JOIN employees e ON d.id = e.dept_id
GROUP BY d.id, d.name
HAVING emp_count > 0
ORDER BY avg_salary DESC;
```

## ⚠️ 주의사항

1. **서브쿼리 성능**: 가능하면 JOIN으로 대체
2. **뷰 업데이트**: 집계 함수 사용 시 업데이트 불가
3. **프로시저 DELIMITER**: 구분자 변경 필수
4. **함수 DETERMINISTIC**: 같은 입력에 같은 출력
