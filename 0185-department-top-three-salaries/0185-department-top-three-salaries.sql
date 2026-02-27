/* Write your PL/SQL query statement below */
SELECT  Department , Employee , Salary
FROM(
    SELECT 
       d.name AS Department,
       e.name AS Employee,
       e.salary as Salary,
       DENSE_RANK() OVER( PARTITION BY d.id ORDER BY e.salary DESC) 
       AS rank
FROM EMPLOYEE e
INNER JOIN DEPARTMENT d
ON e.departmentId = d.id
)
WHERE rank<4;
