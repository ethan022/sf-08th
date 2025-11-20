# 데이터베이스 & SQL

## 📖 개요

SQL 기본 문법과 고급 기능을 학습하는 SQL 파일 모음입니다.

## 📂 파일 목록

프로젝트 경로: `04_database/0430/`

### 내장 함수
- **내장함수_db.sql** - 데이터베이스 및 테스트 데이터 생성
- **내장함수_기초(1).sql** - 기본 내장 함수
- **내장함수_기초(2).sql** - 심화 내장 함수
- **내장함수_실습1.sql** - 실습 문제 1
- **내장함수_실습2.sql** - 실습 문제 2
- **내장함수_실습3.sql** - 실습 문제 3
- **내장함수_형변환.sql** - 데이터 타입 변환

### 서브쿼리
- **서브쿼리_기초.sql** - 서브쿼리 개념 및 기본 사용법
- **서브쿼리_실습1.sql** - 서브쿼리 실습 문제

### 뷰
- **뷰_기초.sql** - 뷰 생성 및 사용
- **뷰_실습2.sql** - 뷰 실습 문제

### 프로그래밍
- **스토어드프로시져,함수_기초.sql** - 저장 프로시저 및 함수

## 🎯 핵심 개념

### 1. 내장 함수

#### 문자열 함수
```sql
-- 문자열 길이
SELECT LENGTH('Hello'), CHAR_LENGTH('안녕');

-- 문자열 연결
SELECT CONCAT('Hello', ' ', 'World');
SELECT CONCAT_WS('-', '2025', '01', '19');  -- 구분자 포함

-- 문자열 추출
SELECT SUBSTRING('Hello World', 1, 5);  -- 'Hello'
SELECT LEFT('Hello', 2);                 -- 'He'
SELECT RIGHT('Hello', 2);                -- 'lo'

-- 대소문자 변환
SELECT UPPER('hello'), LOWER('WORLD');

-- 공백 제거
SELECT TRIM('  Hello  ');
SELECT LTRIM('  Hello'), RTRIM('Hello  ');

-- 문자열 치환
SELECT REPLACE('Hello World', 'World', 'MySQL');
```

#### 숫자 함수
```sql
-- 반올림, 올림, 내림
SELECT ROUND(3.14159, 2);   -- 3.14
SELECT CEIL(3.14);          -- 4
SELECT FLOOR(3.99);         -- 3

-- 절댓값, 제곱, 제곱근
SELECT ABS(-10);            -- 10
SELECT POWER(2, 3);         -- 8
SELECT SQRT(16);            -- 4

-- 나머지
SELECT MOD(10, 3);          -- 1
```

#### 날짜/시간 함수
```sql
-- 현재 날짜/시간
SELECT NOW(), CURDATE(), CURTIME();

-- 날짜 추출
SELECT YEAR(NOW()), MONTH(NOW()), DAY(NOW());
SELECT HOUR(NOW()), MINUTE(NOW()), SECOND(NOW());

-- 날짜 연산
SELECT DATE_ADD(NOW(), INTERVAL 7 DAY);
SELECT DATE_SUB(NOW(), INTERVAL 1 MONTH);
SELECT DATEDIFF('2025-12-31', NOW());

-- 날짜 포맷
SELECT DATE_FORMAT(NOW(), '%Y년 %m월 %d일');
SELECT DATE_FORMAT(NOW(), '%H:%i:%s');
```

#### 집계 함수
```sql
-- COUNT, SUM, AVG, MAX, MIN
SELECT
    COUNT(*) AS 총개수,
    SUM(price) AS 합계,
    AVG(price) AS 평균,
    MAX(price) AS 최댓값,
    MIN(price) AS 최솟값
FROM products;

-- GROUP BY와 함께
SELECT
    category,
    COUNT(*) AS 상품수,
    AVG(price) AS 평균가격
FROM products
GROUP BY category;
```

### 2. 형 변환
```sql
-- 문자열 → 숫자
SELECT CAST('123' AS SIGNED);
SELECT CONVERT('123', SIGNED);

-- 숫자 → 문자열
SELECT CAST(123 AS CHAR);

-- 날짜 변환
SELECT CAST('2025-01-19' AS DATE);
SELECT STR_TO_DATE('2025/01/19', '%Y/%m/%d');
```

### 3. 서브쿼리

#### WHERE 절 서브쿼리
```sql
-- 단일 값 서브쿼리
SELECT name, price
FROM products
WHERE price > (SELECT AVG(price) FROM products);

-- IN 서브쿼리
SELECT name
FROM employees
WHERE dept_id IN (SELECT id FROM departments WHERE location = 'Seoul');

-- EXISTS 서브쿼리
SELECT name
FROM customers c
WHERE EXISTS (
    SELECT 1 FROM orders o
    WHERE o.customer_id = c.id
);
```

#### FROM 절 서브쿼리 (인라인 뷰)
```sql
SELECT dept_name, avg_salary
FROM (
    SELECT dept_id, AVG(salary) AS avg_salary
    FROM employees
    GROUP BY dept_id
) AS dept_avg
JOIN departments ON dept_avg.dept_id = departments.id;
```

#### SELECT 절 서브쿼리 (스칼라 서브쿼리)
```sql
SELECT
    name,
    salary,
    (SELECT AVG(salary) FROM employees) AS avg_salary,
    salary - (SELECT AVG(salary) FROM employees) AS diff
FROM employees;
```

### 4. 뷰 (View)

#### 뷰 생성
```sql
-- 기본 뷰
CREATE VIEW high_salary_employees AS
SELECT name, department, salary
FROM employees
WHERE salary > 5000000;

-- 복잡한 뷰
CREATE VIEW dept_summary AS
SELECT
    d.name AS dept_name,
    COUNT(e.id) AS emp_count,
    AVG(e.salary) AS avg_salary
FROM departments d
LEFT JOIN employees e ON d.id = e.dept_id
GROUP BY d.id, d.name;
```

#### 뷰 사용
```sql
-- 뷰 조회 (일반 테이블처럼 사용)
SELECT * FROM high_salary_employees;
SELECT * FROM dept_summary WHERE emp_count > 10;
```

#### 뷰 관리
```sql
-- 뷰 수정
CREATE OR REPLACE VIEW high_salary_employees AS
SELECT name, department, salary, hire_date
FROM employees
WHERE salary > 6000000;

-- 뷰 삭제
DROP VIEW IF EXISTS high_salary_employees;

-- 뷰 목록 확인
SHOW FULL TABLES WHERE Table_type = 'VIEW';
```

### 5. 스토어드 프로시저

#### 기본 프로시저
```sql
DELIMITER //

CREATE PROCEDURE GetEmployeeCount()
BEGIN
    SELECT COUNT(*) AS total_employees FROM employees;
END //

DELIMITER ;

-- 호출
CALL GetEmployeeCount();
```

#### 매개변수가 있는 프로시저
```sql
DELIMITER //

CREATE PROCEDURE GetEmployeesByDept(IN dept_name VARCHAR(50))
BEGIN
    SELECT name, salary
    FROM employees
    WHERE department = dept_name
    ORDER BY salary DESC;
END //

DELIMITER ;

-- 호출
CALL GetEmployeesByDept('개발팀');
```

#### OUT 매개변수
```sql
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

-- 호출
CALL GetSalaryStats('개발팀', @avg, @max);
SELECT @avg, @max;
```

### 6. 스토어드 함수

```sql
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

-- 사용
SELECT
    name,
    salary,
    CalculateBonus(salary) AS bonus
FROM employees;
```

## 📚 학습 순서

1. **내장함수_기초(1,2)**: SQL 내장 함수 이해
2. **내장함수_형변환**: 데이터 타입 변환
3. **내장함수_실습(1,2,3)**: 실습 문제 풀이
4. **서브쿼리_기초**: 서브쿼리 개념 학습
5. **서브쿼리_실습1**: 서브쿼리 실전 연습
6. **뷰_기초**: 뷰 생성 및 활용
7. **뷰_실습2**: 뷰 실습 문제
8. **스토어드프로시져,함수_기초**: 프로시저와 함수 작성

## 💡 주요 학습 포인트

- ✅ 내장 함수로 데이터 가공
- ✅ 집계 함수와 GROUP BY 활용
- ✅ 서브쿼리로 복잡한 쿼리 작성
- ✅ 뷰로 복잡한 쿼리 단순화
- ✅ 스토어드 프로시저로 로직 캡슐화
- ✅ 함수로 재사용 가능한 코드 작성

## 🎓 실전 활용

### 복잡한 쿼리 예제
```sql
-- 부서별 급여 통계 및 순위
WITH dept_stats AS (
    SELECT
        department,
        AVG(salary) AS avg_salary,
        COUNT(*) AS emp_count
    FROM employees
    GROUP BY department
)
SELECT
    department,
    avg_salary,
    emp_count,
    RANK() OVER (ORDER BY avg_salary DESC) AS salary_rank
FROM dept_stats
WHERE emp_count >= 5;
```

### 데이터 분석 쿼리
```sql
-- 월별 매출 추이
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

## 🔗 다음 단계

→ **05_network_mysql**: C++에서 MySQL 연동하여 실전 프로젝트 구현
