SELECT c1.visited_on, SUM(c2.amount) amount, ROUND(SUM(c2.amount) * 1.0 / COUNT(DISTINCT c2.visited_on), 2) average_amount
FROM (
    SELECT DISTINCT visited_on
    FROM Customer
) c1
JOIN Customer c2 ON
    DATE_ADD((SELECT MIN(visited_on) FROM Customer), INTERVAL 6 DAY) <= c1.visited_on 
    AND DATE_SUB(c1.visited_on, INTERVAL 7 DAY) < c2.visited_on
    AND c2.visited_on <= c1.visited_on
GROUP BY c1.visited_on
ORDER BY c1.visited_on;