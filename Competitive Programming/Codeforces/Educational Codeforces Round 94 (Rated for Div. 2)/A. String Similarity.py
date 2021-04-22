# Question: https://codeforces.com/contest/1400/problem/A
# Solution: https://codeforces.com/contest/1400/submission/90924556

tests = int(input())
while tests:
    tests-=1
    n = int(input())
    s = input()
    ans = ""
    for i in range(n):
        ans += s[i]
        s = s[1:]
    print(ans)