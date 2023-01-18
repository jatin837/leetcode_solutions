select a.sell_date,
count(distinct a.product) as num_sold,
group_concat(distinct a.product order by a.product separator ',') as products
from Activities a
group by a.sell_date
order by a.sell_date;