/* Write your PL/SQL query statement below */
SELECT score ,
DENSE_RANK() OVER(ORDER BY score DESC) AS rank
FROM scores
WHERE score IS NOT NULL;