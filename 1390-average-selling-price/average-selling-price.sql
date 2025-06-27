# Write your MySQL query statement below
select p.product_id,IFNULL(ROUND(SUM(p.price * u.units) / SUM(u.units), 2), 0) AS average_price
from Prices as p
left join UnitsSold as  u
on p.product_id=u.product_id and u.purchase_date>=p.start_date and u.purchase_date<=p.end_date
group by p.product_id

