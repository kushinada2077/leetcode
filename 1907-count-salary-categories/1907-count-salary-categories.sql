SELECT c.category, COUNT(account_id) accounts_count
FROM (
SELECT "Low Salary" category
UNION
SELECT "Average Salary"
UNION
SELECT "High Salary"
) c
LEFT JOIN Accounts
ON CASE
WHEN c.category = "Low Salary" THEN income < 20000
WHEN c.category = "Average Salary" THEN 20000 <= income AND income <= 50000
WHEN c.category = "High Salary" THEN 50000 < income
END
GROUP BY c.category;