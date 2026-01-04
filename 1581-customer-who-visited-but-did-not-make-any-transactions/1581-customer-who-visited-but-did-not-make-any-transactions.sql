SELECT 
    v.customer_id customer_id, 
    COUNT(*) count_no_trans
FROM Visits v
LEFT JOIN Transactions t USING(visit_id)
WHERE t.visit_id IS NULL
GROUP BY v.customer_id;