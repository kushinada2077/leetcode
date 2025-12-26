SELECT ROUND(100.0 * AVG(CASE WHEN main.min_date = sub.customer_pref_delivery_date THEN 1 ELSE 0 END), 2) immediate_percentage
FROM (
SELECT customer_id, MIN(order_date) min_date
FROM Delivery
GROUP BY customer_id
) main
JOIN Delivery sub ON main.customer_id = sub.customer_id AND main.min_date = sub.order_date;