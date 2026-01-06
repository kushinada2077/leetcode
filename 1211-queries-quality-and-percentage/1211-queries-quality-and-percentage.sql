SELECT
    query_name,
    ROUND(AVG(rating / position), 2) quality,
    ROUND(100 * SUM(rating < 3) / COUNT(*), 2) poor_query_percentage
FROM Queries
GROUP BY query_name;