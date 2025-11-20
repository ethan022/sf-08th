-- 1
SELECT name, birth_date, 
	CONCAT(name, " (" ,birth_date," )") name_with_birth
FROM users;

-- 2
SELECT email, RIGHT(email, 11) 
FROM users;

SELECT email, SUBSTRING_INDEX(email, "@", -1) 
FROM users;

SELECT email, SUBSTRING(email, LOCATE('@', email)+1) 
FROM users;

-- 3
SELECT product_name , 
	SUBSTRING_INDEX(product_name, " ",-1) category_keyword
FROM products;




