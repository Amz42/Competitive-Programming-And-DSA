# Question: https://codeforces.com/contest/1475/problem/A
# Solution: https://codeforces.com/contest/1475/submission/105332079

for _ in range(int(input())):
    n = int(input())

    while n%2==0: n/=2
    print("NO" if n==1 else "YES")