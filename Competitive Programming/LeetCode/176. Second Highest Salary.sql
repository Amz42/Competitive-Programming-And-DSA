-- Question: https://leetcode.com/problems/second-highest-salary/

-- Solution-1: https://leetcode.com/submissions/detail/500027977/
SELECT (
    SELECT DISTINCT(Salary) FROM Employee ORDER BY Salary DESC LIMIT 1 OFFSET 1
) as SecondHighestSalary;

-- Solution-2: https://leetcode.com/submissions/detail/500029082/
SELECT MAX(Salary) as SecondHighestSalary FROM Employee WHERE Salary NOT IN (
    SELECT MAX(Salary) FROM Employee
);

-- Solution-3: https://leetcode.com/submissions/detail/500029440/
SELECT MAX(Salary) as SecondHighestSalary FROM Employee WHERE Salary < (
    SELECT MAX(Salary) FROM Employee
);