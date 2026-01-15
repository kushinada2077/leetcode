SELECT employee_id, department_id
FROM Employee main
WHERE
    primary_flag = 'Y'
    OR 1 = (
        SELECT COUNT(*)
        FROM Employee sub
        WHERE main.employee_id = sub.employee_id
    );