-- Question: https://leetcode.com/problems/delete-duplicate-emails/

-- Solution-1: https://leetcode.com/submissions/detail/500019238/
DELETE p1 FROM Person p1, Person p2
WHERE (
    p1.Email = p2.Email AND
    p1.Id > p2.Id
);

-- Solution-2: https://leetcode.com/submissions/detail/500021778/
DELETE FROM Person WHERE Id NOT IN (
    SELECT * FROM (
        SELECT MIN(Id) FROM Person GROUP BY Email
    ) as p
);