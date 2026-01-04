SELECT
(
SELECT DISTINCT e1.salary
FROM Employee e1
WHERE 1 = (
    SELECT COUNT(DISTINCT e2.salary)
    FROM Employee e2
    WHERE e1.salary < e2.salary
)
) SecondHighestSalary;