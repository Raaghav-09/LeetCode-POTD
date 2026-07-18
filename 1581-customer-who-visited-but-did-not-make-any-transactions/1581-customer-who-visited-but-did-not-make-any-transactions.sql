# Write your MySQL query statement below
SELECT vs.customer_id , COUNT(vs.customer_id) as count_no_trans
FROM Visits vs
LEFT JOIN Transactions t
ON vs.visit_id = t.visit_id
WHERE t.transaction_id is NULL
GROUP BY vs.customer_id