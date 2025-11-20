-- 1
CREATE VIEW v_order_summary AS
	SELECT c.customer_id, c.name customer_name, p.name product_name,
		oi.quantity, o.order_date
	FROM customers c
		JOIN orders o ON c.customer_id = o.customer_id
		JOIN order_items oi ON o.order_id = oi.order_id
		JOIN products p ON oi.product_id = p.product_id;

-- 2
SELECT * FROM v_order_summary
ORDER BY customer_name, order_date DESC;

-- 3
CREATE OR REPLACE VIEW v_order_summary AS
	SELECT c.customer_id, c.name customer_name, p.name product_name,
		oi.quantity, o.order_date, o.order_status
	FROM customers c
		JOIN orders o ON c.customer_id = o.customer_id
		JOIN order_items oi ON o.order_id = oi.order_id
		JOIN products p ON oi.product_id = p.product_id
	WHERE o.order_status = "완료";

SELECT * FROM v_order_summary;







