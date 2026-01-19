SELECT
    p1.product_id,
    (CASE
        WHEN MAX(p2.change_date) IS NULL
        THEN 10
        ELSE (
            SELECT new_price
            FROM Products
            WHERE p1.product_id = Products.product_id AND MAX(p2.change_date) = Products.change_date
        )
        END
    ) price  
FROM (
    SELECT product_id
    FROM Products
    GROUP BY product_id
) p1
LEFT JOIN Products p2
ON p1.product_id = p2.product_id AND p2.change_date <= '2019-08-16'
GROUP BY p1.product_id;