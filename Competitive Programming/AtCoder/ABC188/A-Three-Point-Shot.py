# Question: https://atcoder.jp/contests/abc188/tasks/abc188_a
# Solution: https://atcoder.jp/contests/abc188/submissions/19314220

n,m = sorted([int(x) for x in input().split(" ")])
if n+3>m:
    print("Yes")
else:
    print("No")