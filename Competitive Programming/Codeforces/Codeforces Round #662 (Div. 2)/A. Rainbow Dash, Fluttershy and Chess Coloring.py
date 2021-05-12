# Question: https://codeforces.com/contest/1393/problem/A
# Solution: https://codeforces.com/contest/1393/submission/89307808

tests = int(input())
for t in range(tests):
    n = int(input())
    if n&1: print((n+1)//2)
    else: print(n//2+1)