-- Question: https://leetcode.com/problems/nth-highest-salary/

-- Solution: https://leetcode.com/submissions/detail/500037722/
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      SELECT MIN(salary) FROM (
        SELECT DISTINCT(Salary) FROM Employee ORDER BY Salary DESC LIMIT N
      ) AS htable HAVING COUNT(salary) = N
  );
END