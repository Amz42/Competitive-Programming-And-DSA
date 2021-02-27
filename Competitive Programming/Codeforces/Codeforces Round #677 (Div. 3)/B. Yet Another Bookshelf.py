# Question: https://codeforces.com/contest/1433/problem/B
# Solution: https://codeforces.com/contest/1433/submission/96176169

tests = int(input())
for test in range(tests):
    n = int(input())
    l = "".join([x for x in input().split(" ")])
    l = l.strip('0')
    print(l.count('0'))