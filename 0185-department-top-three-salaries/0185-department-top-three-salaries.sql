WITH new_e AS (
    SELECT e.id, e.name employee_name, e.salary, e.departmentId, d.name department_name
    FROM Employee e
    JOIN Department d ON e.departmentId = d.id
)
, base AS (
    SELECT e1.department_name Department, e1.employee_name Employee, e1.salary Salary, COUNT(DISTINCT e2.salary) rnk
    FROM new_e e1
    LEFT JOIN new_e e2
    ON e1.id <> e2.id
    AND e1.departmentId = e2.departmentId
    AND e1.salary < e2.salary
    GROUP BY e1.id
)

SELECT Department, Employee, Salary
FROM base
WHERE rnk < 3;