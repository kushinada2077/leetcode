SELECT w1.id id
FROM Weather w1
WHERE w1.temperature > (
    SELECT w2.temperature
    FROM Weather w2
    WHERE DATE_ADD(w2.recordDate, INTERVAL 1 DAY) = w1.recordDate
);