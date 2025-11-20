USE codingon_store_db;

-- 1. 뷰 생성 및 조회
CREATE VIEW v_customers AS
	SELECT customer_id, name FROM customers;

SELECT customer_id, name FROM customers;
SELECT * FROM v_customers;

CREATE VIEW v_order_price AS
	SELECT order_id,
	ROUND(SUM(quantity * unit_price * (1 - discount_rate / 100))) total_price
	FROM order_items
	GROUP BY order_id;
    
SELECT * FROM v_order_price
WHERE total_price >= 300000;

SELECT order_id, total_price
FROM  (
	SELECT order_id,
	ROUND(SUM(quantity * unit_price * (1 - discount_rate / 100))) total_price
	FROM order_items
	GROUP BY order_id
) sub
WHERE total_price >= 300000;

-- 2. VIEW 수정
CREATE OR REPLACE VIEW v_customer_orders AS
SELECT c.name 이름, o.order_id 주문아이디, o.order_date 주문일
FROM customers c
JOIN orders o ON c.customer_id = o.customer_id;

ALTER VIEW v_customer_orders AS
SELECT c.name 이름, email 이메일, o.order_id "주문 아이디", o.order_date "주문 일", city
FROM customers c
JOIN orders o ON c.customer_id = o.customer_id;

SELECT * FROM v_customer_orders;

-- SELECT시 유의사항
SELECT `주문 아이디` FROM v_customer_orders;

-- 3. 뷰의구조 및 정의 확인
DESC v_customer_orders;
SHOW CREATE VIEW v_customer_orders;

-- 4. VIEW로 데이터 수정
CREATE OR REPLACE VIEW v_customers AS
SELECT customer_id, name FROM customers
WHERE customer_id < 20
WITH CHECK OPTION;

UPDATE v_customers
SET name = "홍길남"
WHERE customer_id = 1;

-- 5. VIEW로 데이터 입력
INSERT INTO v_customers (customer_id, name) 
VALUES (10, "테스트");

INSERT INTO v_customers
VALUES (11, "테스트2");

INSERT INTO v_customers
VALUES (30, "테스트3");

SELECT * FROM v_customers;
SELECT * FROM customers;

-- 6. VIEW 삭제
DROP VIEW v_customers;

-- 7. VIEW 목록 조회
SHOW FULL TABLES IN codingon_store_db WHERE TABLE_TYPE LIKE 'VIEW';


















