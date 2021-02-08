# Question: https://codeforces.com/contest/1463/problem/A
# Solution: https://codeforces.com/contest/1463/submission/101526426

tests = 1
tests = int(input())
for _ in range(tests):
    a,b,c = sorted([int(x) for x in input().split(" ")])
    sm = a+b+c
    if sm%9!=0 or a<sm//9:
        print("NO")
    else:
        print("YES")