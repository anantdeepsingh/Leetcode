# Write your MySQL query statement below
update Salary 
set sex= Case
        when sex='f' then 'm'
        else 'f'
        END
