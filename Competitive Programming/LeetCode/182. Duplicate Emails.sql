-- Question: https://leetcode.com/problems/duplicate-emails/

-- Solution-1: https://leetcode.com/submissions/detail/500023723/
SELECT Email FROM Person GROUP BY Email HAVING COUNT(*) > 1;