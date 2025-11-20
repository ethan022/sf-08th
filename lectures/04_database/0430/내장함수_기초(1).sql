USE function_db;

-- 문자 함수
-- CONCAT 문자열 결합
SELECT name, birth_date, 
	CONCAT(name, " (" ,birth_date," )") name_with_birth
FROM users;

-- LEFT 일부 문자열 추출(왼쪽부터)
SELECT product_name, LEFT(product_name, 2)
FROM products;

-- SUBSTRING 지정한 위치에서 문자열 추출
SELECT name, SUBSTRING(name, 2, 2) first_name
FROM users;

-- SUBSTRING_INDEX
SELECT product_name, SUBSTRING_INDEX(product_name, " ", -3)
FROM products;

-- UPPER 대문자 변환
SELECT name, email, UPPER(email) upper_email 
FROM users;

-- REPLACE 일부 문자열을 변경
SELECT name, REPLACE(name, '이', 'LEE') replaced_name
FROM users;

-- 수학함수
-- ROUND : 반올림, CEIL : 올림, FLOOR : 내림
SELECT ROUND(3.56);
SELECT ROUND(1234.5678, 2);
SELECT ROUND(1234.5678, -2);

-- MOD : 나머지 구하기
SELECT MOD(10, 3);

-- ABS : 절대값
SELECT ABS(-100);

-- RAND : 0~1 난수 생성
SELECT RAND();
SELECT ROUND(RAND() * 45);

SELECT user_id, ROUND(RAND() * 10000) recommended_code
FROM users;

-- 날짜함수
-- NOW, CURDATE, CURTIME 현재 날짜,시간
SELECT NOW();
SELECT CURDATE();
SELECT CURTIME();

-- DATEDIFF 날짜의 차이 계산
SELECT DATEDIFF(CURDATE(), "2025-03-14");
SELECT created_at, DATEDIFF(NOW(), created_at)
FROM orders;

-- DATE_ADD 날짜에 더하기
SELECT DATE_ADD("2025-03-14", INTERVAL 3 DAY);

-- YEAR, MONTH, DAY
SELECT 
	YEAR("2025-03-14") year, 
	MONTH("2025-03-14") month, 
    DAY("2025-03-14") day;










