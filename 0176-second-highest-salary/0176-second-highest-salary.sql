SELECT (
SELECT DISTINCT salary
FROM (
SELECT salary, DENSE_RANK() OVER (ORDER BY salary DESC) rnk
FROM Employee
) e
WHERE rnk = 2
) SecondHighestSalary;