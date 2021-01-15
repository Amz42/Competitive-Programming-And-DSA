# Question: https://codeforces.com/contest/1473/problem/B
# Solution: https://codeforces.com/contest/1473/submission/104442607

import math
for _ in range(int(input())):
    a = input().strip(" ")
    b = input().strip(" ")
    n = len(a)
    m = len(b)
    lcm = (n*m)//(math.gcd(n,m));

    a = a*(lcm//n)
    b = b*(lcm//m)

    print(a if a==b else "-1")