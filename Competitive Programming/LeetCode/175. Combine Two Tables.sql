-- Question: https://leetcode.com/problems/combine-two-tables/

-- Solution: https://leetcode.com/submissions/detail/504394099/
SELECT FirstName, LastName, City, State
FROM Person LEFT JOIN Address ON Person.PersonId = Address.PersonId;