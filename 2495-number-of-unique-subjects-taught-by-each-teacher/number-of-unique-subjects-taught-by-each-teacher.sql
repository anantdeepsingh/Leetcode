# Write your MySQL query statement below
select t1.teacher_id, COUNT(DISTINCT t2.subject_id) AS cnt
from Teacher t1
join Teacher t2
on t1.teacher_id=t2.teacher_id
group by t1.teacher_id