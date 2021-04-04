# Question: https://codeforces.com/contest/1405/problem/A
# Solution: https://codeforces.com/contest/1405/submission/92027545

for t in range(int(input())):
    n = int(input())
    l =[int(x) for x in input().split(" ")][::-1]
    print(*l)