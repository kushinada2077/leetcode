SELECT
    DATE_FORMAT(trans_date, '%Y-%m') month,
    country,
    COUNT(*) trans_count,
    SUM(state = 'approved') approved_count,
    SUM(amount) trans_total_amount,
    SUM(CASE WHEN state = 'approved' THEN amount ELSE 0 END) approved_total_amount
FROM Transactions
GROUP BY month, country;