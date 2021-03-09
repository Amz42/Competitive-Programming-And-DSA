# Question: https://codeforces.com/contest/1419/problem/C
# Solution: https://codeforces.com/contest/1419/submission/96378545

for _ in range(int(input())):
    n,x = [int(x) for x in input().split(" ")]
    l = [int(x) for x in input().split(" ")]
    s = list(set(l))
    if len(s)==1 and s[0]==x:
        print(0)
    elif x in l or sum([x-i for i in l])==0:
        print(1)
    else:
        print(2)