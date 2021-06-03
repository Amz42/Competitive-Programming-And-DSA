-- question: https://leetcode.com/problems/swap-salary/
-- solution-1: https://leetcode.com/submissions/detail/499987404/
-- solution-2: https://leetcode.com/submissions/detail/499991339/

-- solution-1
UPDATE Salary
SET sex = 
    CASE sex
        WHEN 'f' then 'm'
        WHEN 'm' then 'f'
        ELSE sex
    END
;

-- solution-2
UPDATE Salary SET sex = IF(sex = 'm', 'f', 'm');