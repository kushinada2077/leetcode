SELECT product_id, year first_year, quantity, price
FROM Sales m
WHERE EXISTS (
    SELECT 1
    FROM (
        SELECT product_id, MIN(year) min_year
        FROM Sales
        GROUP BY product_id
    ) s
    WHERE m.product_id = s.product_id AND m.year = s.min_year
);