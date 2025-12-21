SELECT id FROM Weather AS T
WHERE temperature > 
    (SELECT temperature 
        FROM Weather AS Y
        WHERE DATEDIFF(T.recordDate, Y.recordDate) = 1
    )