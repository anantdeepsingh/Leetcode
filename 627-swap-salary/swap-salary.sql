# Write your MySQL query statement below
update Salary 
set sex= Case
        when sex='f' then 'm'
        when sex='m' then 'f'
        END
