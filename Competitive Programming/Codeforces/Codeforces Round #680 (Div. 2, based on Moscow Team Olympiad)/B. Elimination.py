# Question: https://codeforces.com/contest/1445/problem/B
# Solution: https://codeforces.com/contest/1445/submission/97318267

tests = int(input())
for t in range(tests):
    a,b,c,d = [int(x) for x in input().split(" ")]
    print(max([a+b,c+d]))