# Write your MySQL query statement below
SELECT ROUND(SUM(tiv_2016), 2) as tiv_2016
FROM Insurance
WHERE pid IN (
    SELECT pid
    FROM Insurance
    WHERE tiv_2015 IN (
        SELECT tiv_2015
        FROM Insurance
        GROUP BY tiv_2015
        HAVING COUNT(*) > 1
    )
    INTERSECT
    SELECT pid
    FROM Insurance
    WHERE (lat, lon) IN (
        SELECT lat, lon
        FROM Insurance
        GROUP BY lat, lon
        HAVING COUNT(*) = 1
    )
);

