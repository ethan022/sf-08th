-- 1
-- 상품 가격이 '평균'보다 높은 경우 '고가' 아니면 '저가'
SET @avg_price = (SELECT AVG(price) FROM products);

SELECT product_name, price,
	IF(price > @avg_price, "고가", "저가") price_grade
FROM products;

SELECT product_name, price,
	IF(price > (SELECT AVG(price) FROM products), "고가", "저가") price_grade
FROM products;

-- 2
-- 이메일이 NULL인 경우 '이메일 미입력'으로 표시하시오.
SELECT user_id, name, 
	IFNULL(email, '이메일 미입력') checked_email
FROM users;

-- 3
-- 배송완료된 주문 중, 5일 이상 지난 주문은 '후기 요청', 그 외는 '배송 확인'으로 표시하시오.(case 사용)
SELECT order_id, order_status, created_at,
	CASE 
		WHEN order_status = '배송완료' AND DATEDIFF(now(), created_at) >= 5
			THEN '후기 요청'
		WHEN order_status = '배송완료' THEN '배송 확인'
        ELSE '대상 아님'
	END followup_status
FROM orders;


