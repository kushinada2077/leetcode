SELECT 
    v.customer_id customer_id, 
    COUNT(*) - COUNT(t.transaction_id) count_no_trans
FROM Visits v
LEFT JOIN Transactions t USING(visit_id)
GROUP BY v.customer_id
HAVING COUNT(t.transaction_id) <> COUNT(*);