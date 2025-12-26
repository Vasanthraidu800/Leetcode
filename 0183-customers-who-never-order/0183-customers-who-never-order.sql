/* Write your PL/SQL query statement below */
SELECT c.name as CUSTOMERS FROM
customers c
LEFT JOIN
orders o
ON c.id=o.customerId
WHERE o.id is NULL;