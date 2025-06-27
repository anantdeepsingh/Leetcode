# Write your MySQL query statement below
select project_id,round(sum(experience_years)/count(*),2) as average_years
from Project
join Employee
on Employee.employee_id=Project.employee_id
group by project_id

