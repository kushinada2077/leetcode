SELECT u.unique_id unique_id, e.name name
FROM Employees e
LEFT JOIN EmployeeUNI u USING(id);