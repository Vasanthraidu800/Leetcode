# Write your MySQL query statement below
select id, 
CASE 
    WHEN P_id is NULL Then 'Root'
    WHEN id IN (select p_id from tree) THEN 'Inner'
    ELSE 'Leaf'
END AS type
FROM tree;