# Write your MySQL query statement below
select e1.employee_id,ifnull(e2.department_id,e1.department_id) as department_id
from Employee e1
left join Employee e2
on e1.employee_id=e2.employee_id and e2.primary_flag='Y'
group by e1.employee_id