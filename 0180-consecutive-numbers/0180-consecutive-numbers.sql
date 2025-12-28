SELECT DISTINCT l1.num ConsecutiveNums
FROM Logs l1
WHERE EXISTS (
    SELECT 1
    FROM Logs l2
    WHERE l1.id + 1 = l2.id AND l1.num = l2.num
) AND
EXISTS (
    SELECT 1
    FROM Logs l3
    WHERE l1.id + 2 = l3.id AND l1.num = l3.num
);