-- SELECT requester_id as id, COUNT(requester_id) AS num
-- FROM (
--     SELECT r1.requester_id
--     FROM RequestAccepted r1

--     UNION all

--     SELECT r1.requester_id
--     FROM RequestAccepted r1
--     JOIN RequestAccepted r2
--     ON r1.requester_id = r2.accepter_id
-- ) AS sub
-- GROUP BY requester_id
-- ORDER BY requester_id DESC
-- limit 1 OFFSET 0

select requester_id as id,count(*) as num
from(
    SELECT r1.requester_id
FROM RequestAccepted r1
    UNION all
SELECT r1.accepter_id
FROM RequestAccepted r1
) as c
group by id
order by num desc
limit 1




    