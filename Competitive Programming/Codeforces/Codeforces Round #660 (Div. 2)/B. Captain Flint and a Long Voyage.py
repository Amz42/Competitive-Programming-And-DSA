# Question: https://codeforces.com/contest/1388/problem/B
# Solution: https://codeforces.com/contest/1388/submission/88532248

import math
tests = int(input())
for t in range(tests):
    n=int(input())
    d = math.ceil(n/4)
    print("9"*(n-d)+"8"*d)