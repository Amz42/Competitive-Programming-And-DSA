# Question: https://codeforces.com/contest/1437/problem/B
# Solution: https://codeforces.com/contest/1437/submission/96937337

for _ in range(int(input().strip())):
    n = int(input().strip())
    s = input().strip(" ")
    copy = "01"*(n//2) if s[0]=='0' else "10"*(n//2)
    i,ans = 0,0
    while i<n:
        if s[i]!=copy[i]:
            ans += 1
            while i<n and s[i]!=copy[i]: i += 1
        else:
            i += 1
    print(ans)