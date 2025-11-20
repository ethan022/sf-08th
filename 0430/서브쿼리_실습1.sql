-- 1. 카테고리가 '전자기기'인 상품 중, 가장 가격이 높은 상품의 이름과 가격을 조회하시오.
SELECT * FROM products
WHERE category = "전자기기" 
AND price = (
	SELECT MAX(price) FROM products
	WHERE category = "전자기기" 
);

-- 2. 결제가 '신용카드'로 이루어진 주문을 한 고객의 이름과 ID를 조회하시오.
SELECT * FROM customers;
SELECT * FROM orders;

SELECT name, customer_id
FROM customers
WHERE customer_id IN (
	SELECT customer_id
	FROM orders
	WHERE payment_method = "신용카드"
);

-- 3. 1회 이상 주문한 고객 중 가장 최근에 주문한 고객의 이름과 주문일을 출력하시오.
SELECT name, order_date
FROM customers c
	JOIN orders o ON c.customer_id = o.customer_id
WHERE order_date = (
	SELECT MAX(order_date) FROM orders
);

SELECT name, order_date
FROM customers c
	JOIN orders o ON c.customer_id = o.customer_id
ORDER BY order_date DESC
LIMIT 1;

-- 4. 서브쿼리를 사용하여, 주문별 총 결제 금액이 30만 원 이상인 주문의 주문 ID와 금액을 출력하시오
SELECT * FROM order_items;
SELECT * FROM orders;

SELECT order_id, total_price
FROM  (
	SELECT order_id,
	ROUND(SUM(quantity * unit_price * (1 - discount_rate / 100))) total_price
	FROM order_items
	GROUP BY order_id
) sub
WHERE total_price >= 300000;

SELECT order_id,
ROUND(SUM(quantity * unit_price * (1 - discount_rate / 100))) total_price
FROM order_items
GROUP BY order_id
HAVING total_price >= 300000;









