/* Write your PL/SQL query statement below */
SELECT TO_CHAR(date_id, 'YYYY-MM-DD') AS date_id, make_name as make_name, COUNT(DISTINCT(lead_id)) as Unique_leads, COUNT(DISTINCT(partner_id)) as unique_partners FROM dailysales
GROUP BY  date_id , make_name;