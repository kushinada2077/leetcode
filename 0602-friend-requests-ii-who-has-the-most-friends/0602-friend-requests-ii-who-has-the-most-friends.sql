SELECT r1.id
    , (
        SELECT COUNT(DISTINCT friend_id)
        FROM (
            (
        SELECT DISTINCT requester_id friend_id
        FROM RequestAccepted
        WHERE accepter_id = r1.id
            )
    UNION
    (
        SELECT DISTINCT accepter_id
        FROM RequestAccepted
        WHERE requester_id = r1.id
    )
    ) f
     ) num




FROM (
    (
        SELECT DISTINCT requester_id id
        FROM RequestAccepted
    )
    UNION
    (
        SELECT DISTINCT accepter_id
        FROM RequestAccepted
    )
    ) r1
GROUP BY r1.id
ORDER BY num DESC
LIMIT 1;