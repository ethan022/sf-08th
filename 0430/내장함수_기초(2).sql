-- IF
USE codingon_db;

SELECT name, gender,
	IF(gender = "남", "Male", "Female") gender_eng
FROM student;

USE codingon_store_db;

SELECT name, price,
	IF(price >= 10000, "비쌈", "저렴") price_level
FROM products;

-- IFNULL
SELECT * FROM customers;

SELECT name, IFNULL(phone, "전화번호 없음")
FROM customers;

SELECT name, IFNULL(membership_level, "Iron")
FROM customers;

SELECT order_id, order_status,
	IFNULL(order_status, '주문취소') order_status_edit
FROM orders;

-- NULLIF
SELECT order_id, order_status,
	NULLIF(order_status, '처리중') order_status_edit
FROM orders;

-- CASE
SELECT order_id, order_status,
	CASE order_status
		WHEN '완료' THEN '결제가 완료됐어요'
        WHEN '배송중' THEN '배송중이에요'
        WHEN '처리중' THEN '주문이 처리되고 있어요'
        ELSE '상태를 알 수 없어요'
	END status_label
FROM orders;

use function_db;
SELECT order_id, created_at,
	DATEDIFF(now(), created_at) days_ago,
    CASE
		WHEN DATEDIFF(now(), created_at) <= 3 THEN "최근 주문"
		WHEN DATEDIFF(now(), created_at) <= 7 THEN "지난주 주문"
        ELSE "오래된 주문"
	END order_age
FROM orders;











