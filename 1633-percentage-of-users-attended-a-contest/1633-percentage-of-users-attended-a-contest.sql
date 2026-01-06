SELECT
    r.contest_id contest_id,
    ROUND(100 * COUNT(DISTINCT u.user_id) / (SELECT COUNT(*) FROM Users), 2) percentage
FROM Users u
RIGHT JOIN Register r
ON u.user_id = r.user_id
GROUP BY r.contest_id
ORDER BY percentage DESC, r.contest_id;