select max(p1.salary) as SecondHighestSalary
from Employee p1
join Employee p2
on p1.salary<p2.salary
-- join helps in putting null value by it self no need to put it manually 