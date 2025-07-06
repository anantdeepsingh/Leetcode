# Write your MySQL query statement below
select x,y,z,('Yes') as triangle
from Triangle
where x+y>z and y+z>x and x+z>y
union 
select x,y,z,('No') as triangle
from triangle
where x+y<=z or y+z<=x or x+z<=y