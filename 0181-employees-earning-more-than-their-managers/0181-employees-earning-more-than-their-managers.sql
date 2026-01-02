/* Write your PL/SQL query statement below */
SELECT e1.name as Employee
FROM 
employee e1 
JOIN
employee e2
ON e1.managerId = e2.id AND e1.salary>e2.salary;
