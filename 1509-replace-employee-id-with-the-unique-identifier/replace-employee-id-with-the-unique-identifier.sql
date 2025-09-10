# Write your MySQL query statement below
select ifnull(e2.unique_id,null) as unique_id ,e1.name 
from Employees e1 left join
employeeUNI e2 on e1.id=e2.id

