# Write your MySQL query statement below
SELECT empu.unique_id AS unique_id , emp.name AS  name
FROM Employees emp
LEFT JOIN EmployeeUNI empu
ON emp.id = empu.id
