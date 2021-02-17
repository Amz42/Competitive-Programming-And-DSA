# Question: https://codeforces.com/contest/1430/problem/C
# Solution: https://codeforces.com/contest/1430/submission/95227426

import math
for _ in range(int(input())):
    n = int(input())
    print(2)
    l = [i for i in range(1,n+1)]
    avg = l[-1]
    while n>1:
        print(avg,n-1)
        avg = math.ceil((avg+n-1)/2)
        n-=1