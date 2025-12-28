SELECT p1.product_id, (CASE WHEN p3.change_date IS NULL THEN 10 ELSE p3.new_price END) price
FROM
(
SELECT DISTINCT product_id
FROM Products
) p1
LEFT JOIN (
    SELECT product_id, MAX(change_date) max_date
    FROM Products p3
    WHERE p3.change_date <= '2019-08-16'
    GROUP BY p3.product_id
    ) p2
    ON p1.product_id = p2.product_id
LEFT JOIN Products p3 
ON p1.product_id = p3.product_id AND p2.max_date = p3.change_date