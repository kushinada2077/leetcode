SELECT main.person_name
FROM (
SELECT q1.person_name, SUM(q2.weight) weight_sum
FROM Queue q1
JOIN Queue q2
ON q2.turn <= q1.turn
GROUP BY q1.person_id, q1.turn HAVING SUM(q2.weight) <= 1000
) main
ORDER BY main.weight_sum DESC
LIMIT 1;