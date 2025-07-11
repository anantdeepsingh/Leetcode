# Write your MySQL query statement below
select e.name,b.bonus
from Employee e
left join Bonus b
on e.empId=b.empId
having b.bonus<1000 or b.bonus is NULL