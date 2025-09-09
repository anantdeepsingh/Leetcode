# Write your MySQL query statement below
select e.employee_id
from Employees e
where salary<30000 and (e.manager_id is not null)  and 0>=(
    select count(*)
    from Employees e1
    where e.manager_id=e1.employee_id
) 
order by e.employee_id