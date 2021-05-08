# Question: https://leetcode.com/problems/power-of-three/
# Solution: https://leetcode.com/submissions/detail/490282906/

class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        p3 = 3**19
        if n <= 0: return False
        return (True if p3%n==0 else False)