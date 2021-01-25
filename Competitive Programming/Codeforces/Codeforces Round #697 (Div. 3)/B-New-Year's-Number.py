# Question: https://codeforces.com/contest/1475/problem/B
# Solution: https://codeforces.com/contest/1475/submission/105330937

for _ in range(int(input())):
    n = int(input())
    rem  = n%2020
    div = n//2020

    if rem<=div:
        print("YES")
    else:
        print("NO")