use codingon_store_db;

-- WHERE절 서브쿼리
SELECT name, price
FROM products
WHERE price > (
	SELECT AVG(price) FROM products
);

-- FROM절 서브쿼리
-- 카테고리별 평균 가격을 구하고, 평균이 30,000원 이상인 카테고리만 출력
SELECT category, avg_price
FROM (
	SELECT category, AVG(price) avg_price
	FROM products
		GROUP BY category
) category_product
WHERE avg_price > 30000;

-- SELECT절 서브쿼리
-- 각 고객의 이름과 해당 고객의 총 주문 수를 함께 출력
SELECT name, 
	(SELECT COUNT(*)
		FROM orders
        WHERE customer_id = customers.customer_id
    ) order_count
FROM customers;

SELECT name, count(order_id)
FROM customers c
	LEFT JOIN orders o ON c.customer_id = o.customer_id
GROUP BY name;













