# Write your MySQL query statement below
select e.employee_id, 
case 
when e.name not like 'M%' and e.employee_id%2 then
  e.salary
else
  0
end
as bonus
from Employees e
order by e.employee_id;