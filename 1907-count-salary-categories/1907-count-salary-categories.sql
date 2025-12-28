SELECT cg.category, COUNT(s.category) accounts_count
FROM (
    SELECT "High Salary" category
    UNION ALL
    SELECT "Low Salary"
    UNION ALL
    SELECT "Average Salary"
) cg
LEFT JOIN (
    SELECT
        CASE 
            WHEN income < 20000 THEN 'Low Salary'
            WHEN income <= 50000 THEN 'Average Salary'
            ELSE 'High Salary'
        END category 
    FROM Accounts
) s
ON cg.category = s.category
GROUP BY cg.category;