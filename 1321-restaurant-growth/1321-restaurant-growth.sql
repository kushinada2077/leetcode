SELECT
    c1.visited_on,
    SUM(c2.amount) amount,
    ROUND(SUM(c2.amount) / 7, 2) average_amount
FROM (
    SELECT DISTINCT visited_on
    FROM Customer
) c1
JOIN Customer c2
ON c2.visited_on BETWEEN
    DATE_SUB(c1.visited_on, INTERVAL 6 DAY) AND
    c1.visited_on
GROUP BY c1.visited_on HAVING DATE_SUB(MAX(c2.visited_on), INTERVAL 6 DAY) >= (SELECT MIN(visited_on) FROM Customer)
ORDER BY c1.visited_on;