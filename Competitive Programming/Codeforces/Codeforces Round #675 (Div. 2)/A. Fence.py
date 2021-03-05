# Question: https://codeforces.com/contest/1422/problem/A
# Solution: https://codeforces.com/contest/1422/submission/94664060

for _ in range(int(input())):
    a,b,c = sorted([int(x) for x in input().split(" ")])
    print(1+abs(c-a-b))