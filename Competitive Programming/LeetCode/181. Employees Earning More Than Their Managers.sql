-- Question: https://leetcode.com/problems/employees-earning-more-than-their-managers/

-- Solution: https://leetcode.com/submissions/detail/504414610/
SELECT e1.Name AS 'Employee' FROM
Employee e1 , Employee e2 WHERE e1.ManagerId = e2.Id AND e1.Salary > e2.Salary;