# Question: https://codeforces.com/contest/1428/problem/B
# Solution: https://codeforces.com/contest/1428/submission/95778199

for _ in range(int(input())):
    n = int(input())
    l = [-1 for i in range(n)]
    s = input()
    
    if '>' in s and '<' in s: m1 = 0
    else: m1 = 1
    
    s = s[n-1]+s
    
    for i in range(n):
        # always back available
        if s[i]=='-' or s[i+1]=='-': l[i]=1
        # no back
        if s[i]+s[i+1] in ["<>","><"]:
            l[i]=0
            
    for i in range(n):
        if l[i]==-1: l[i] = m1
    
    print(sum(l))