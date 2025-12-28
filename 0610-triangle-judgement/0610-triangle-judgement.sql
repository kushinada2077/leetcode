SELECT *, (CASE WHEN x >= y + z OR y >= x + z OR z >= x + y THEN 'No' ELSE 'Yes' END) triangle
FROM Triangle;