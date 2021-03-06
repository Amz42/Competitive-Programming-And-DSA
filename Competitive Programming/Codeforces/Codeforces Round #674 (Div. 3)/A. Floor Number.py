# Question: https://codeforces.com/contest/1426/problem/A
# Solution: https://codeforces.com/contest/1426/submission/95389803

import math
for _ in range(int(input())):
    n,x = [int(x) for x in input().split(" ")]
    if(n<3):
        print(1)
        continue
    n -= 2
    print(1+math.ceil(n/x))