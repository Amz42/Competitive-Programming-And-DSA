# Question: https://codeforces.com/contest/1453/problem/A
# Solution: https://codeforces.com/contest/1453/submission/100353553

tests = 1
tests = int(input())
for _ in range(tests):
    n,m = [int(x) for x in input().split(" ")]
    l = set([int(x) for x in input().split(" ")])
    t = set([int(x) for x in input().split(" ")])
    print( len(list(l&t)) )