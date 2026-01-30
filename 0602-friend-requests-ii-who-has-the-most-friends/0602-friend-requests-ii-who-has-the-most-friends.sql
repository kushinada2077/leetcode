WITH all_ids AS (
    SELECT DISTINCT requester_id id
    FROM RequestAccepted
    UNION
    SELECT DISTINCT accepter_id
    FROM RequestAccepted
)

SELECT id, COUNT(f_id) num
FROM (
(SELECT a1.id id, r1.accepter_id f_id
FROM all_ids a1
JOIN RequestAccepted r1 ON a1.id = r1.requester_id)
UNION ALL
(SELECT a2.id, r2.requester_id f_id
FROM all_ids a2
JOIN RequestAccepted r2 ON a2.id = r2.accepter_id)
) main
GROUP BY id
ORDER BY COUNT(f_id) DESC
LIMIT 1;