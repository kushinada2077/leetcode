SELECT 
    p.product_id product_id,
    COALESCE(ROUND(SUM(COALESCE(p.price * u.units, 0)) / SUM(COALESCE(u.units, 0)), 2), 0) average_price
FROM Prices p
LEFT JOIN UnitsSold u
ON
    p.product_id = u.product_id
    AND p.start_date <= u.purchase_date
    AND u.purchase_date <= p.end_date
GROUP BY p.product_id