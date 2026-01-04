SELECT (
SELECT DISTINCT salary
FROM (
SELECT DISTINCT salary, DENSE_RANK() OVER (ORDER BY salary DESC) rnk
FROM Employee
) e
WHERE rnk = 2
) SecondHighestSalary;