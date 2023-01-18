# Write your MySQL query statement below
select e.employee_id, (e.salary)*(e.name not like 'M%')*(e.employee_id%2) as bonus from Employees e
order by e.employee_id;