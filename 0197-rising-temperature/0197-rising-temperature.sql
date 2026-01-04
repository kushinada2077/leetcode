SELECT w1.id id
FROM Weather w1
WHERE EXISTS (
    SELECT 1
    FROM Weather w2
    WHERE 
        DATE_ADD(w2.recordDate, INTERVAL 1 DAY) = w1.recordDate
        AND w2.temperature < w1.temperature
);