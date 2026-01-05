SELECT s.user_id user_id, ROUND(AVG(COALESCE(action = 'confirmed', 0)), 2) confirmation_rate
FROM Signups s
LEFT JOIN Confirmations c ON s.user_id = c.user_id
GROUP BY s.user_id;