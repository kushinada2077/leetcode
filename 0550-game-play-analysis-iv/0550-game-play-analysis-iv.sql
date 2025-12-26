SELECT ROUND(COUNT(*) * 1.0 / (SELECT COUNT(DISTINCT player_id) FROM Activity), 2) fraction
FROM activity
WHERE (player_id, DATE_SUB(event_date, INTERVAL 1 DAY)) IN
(
SELECT player_id, MIN(event_date) first_day
FROM Activity
GROUP BY player_id
);