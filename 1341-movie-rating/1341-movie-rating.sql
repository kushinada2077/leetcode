(
        SELECT u.name results
        FROM MovieRating m 
        JOIN Users u ON m.user_id = u.user_id 
        GROUP BY m.user_id, u.name
        ORDER BY COUNT(*) DESC, u.name
        LIMIT 1
    ) 
    UNION ALL
    (
        SELECT m2.title
        FROM MovieRating m1
        JOIN Movies m2 ON m1.movie_id = m2.movie_id
        WHERE 
            YEAR(m1.created_at) = '2020' AND
            MONTH(m1.created_at) = '02'
        GROUP BY m1.movie_id, m2.title
        ORDER BY AVG(m1.rating) DESC, m2.title
        LIMIT 1
    )