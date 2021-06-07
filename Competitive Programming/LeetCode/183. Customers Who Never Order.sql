-- Question: https://leetcode.com/problems/customers-who-never-order/

-- Solution-1: https://leetcode.com/submissions/detail/504391826/
SELECT Name AS Customers FROM Customers c LEFT JOIN Orders o ON c.Id = o.CustomerId
WHERE o.CustomerId IS NULL;

-- Solution-2: https://leetcode.com/submissions/detail/504390163/
SELECT Name AS Customers FROM Customers WHERE Id NOT IN (
    SELECT CustomerId FROM Orders
);