SELECT
    id, 
    CASE
    WHEN s1.id % 2 = 0 THEN (SELECT student FROM Seat WHERE s1.id - 1 = id)
    WHEN s1.id % 2 = 1 AND s1.id = (SELECT COUNT(*) FROM Seat) THEN s1.student
    ELSE (SELECT student FROM Seat WHERE s1.id + 1 = id) 
    END student
FROM Seat s1