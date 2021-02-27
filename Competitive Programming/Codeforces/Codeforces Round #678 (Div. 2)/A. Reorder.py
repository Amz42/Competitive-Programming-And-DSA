# Question: https://codeforces.com/contest/1436/problem/A
# Solution: https://codeforces.com/contest/1436/submission/96538450

for _ in range(int(input())):
    n,m = [int(x) for x in input().split(" ")]
    l = [int(x) for x in input().split(" ")]
    if sum(l)==m:
        print("YES")
    else:
        print("NO")