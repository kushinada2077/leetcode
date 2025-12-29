SELECT ROUND(SUM(i1.tiv_2016), 2) tiv_2016
FROM Insurance i1
WHERE
    EXISTS (
        SELECT 1
        FROM Insurance
        WHERE i1.pid <> pid AND i1.tiv_2015 = tiv_2015
    )
    AND
    NOT EXISTS (
        SELECT 1
        FROM Insurance
        WHERE i1.pid <> pid AND i1.lat = lat AND i1.lon = lon
    );