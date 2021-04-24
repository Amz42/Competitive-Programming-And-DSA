# Question: https://codeforces.com/contest/1282/problem/A
# Solution: https://codeforces.com/contest/1282/submission/70624602

test=int(input())
for t in range(test):
    a,b,c,r = [int(x) for x in input().split(" ")]
    cs,ce,wait=c-r,c+r,0
    if a>b: a,b=b,a
    if (a>=cs and a<=ce) and (b>=cs and b<=ce):
        print(0)
        continue
    elif not(cs>=a and cs<=b) and not(ce>=a and ce<=b):
        print(b-a)
        continue
    else:
        if cs>=a and cs<=b:
            wait += cs-a
        if ce>=a and ce<=b:
            wait += b-ce
        print(wait)