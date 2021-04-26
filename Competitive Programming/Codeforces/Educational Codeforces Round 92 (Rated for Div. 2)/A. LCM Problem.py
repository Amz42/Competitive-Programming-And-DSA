# Question: https://codeforces.com/contest/1389/problem/A
# Solution: https://codeforces.com/contest/1389/submission/88391443

for t in range(int(input())):
    l,r = [int(x) for x in input().split()]
    if 2*l>r:
        print("-1 -1")
    else:
        print(l,2*l)