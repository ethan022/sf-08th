-- 1
SELECT ROUND(AVG(price),1) avg_price_rounded
FROM products;

-- 2
SELECT order_id, created_at,
	datediff(now(), created_at) days_ago
FROM orders
WHERE datediff(now(), created_at) <= 7;
    
-- 3
SELECT user_id, name, email FROM users
WHERE MOD(user_id, 2) = 1 
	AND (name LIKE "%김%" OR name LIKE "%이%");
    
-- 4
SELECT order_id, order_status, created_at,
	DATEDIFF(now(), created_at) days_since_order
FROM orders
WHERE order_status = "배송완료"
	AND DATEDIFF(now(), created_at) >= 7;







    
    
    