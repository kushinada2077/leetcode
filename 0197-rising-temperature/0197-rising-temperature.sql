SELECT w1.id id
FROM Weather w1
CROSS JOIN Weather w2
WHERE
    w2.temperature < w1.temperature
    AND DATEDIFF(w1.recordDate, w2.recordDate) = 1;