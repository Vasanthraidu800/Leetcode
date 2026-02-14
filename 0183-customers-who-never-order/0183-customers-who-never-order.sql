--SCMR Subquery --> Single Column Multiple Row
-- SELECT customerId from orders
SELECT name AS customers from customers
where id not in
(SELECT customerid from orders);