SELECT p.product_name product_name, SUM(o.unit) unit
FROM Products p
JOIN Orders o
ON 
    p.product_id = o.product_id
    AND '2020-02-01' <= o.order_date
    AND o.order_date < '2020-03-01'
GROUP BY p.product_id
HAVING SUM(o.unit) >= 100;