# Question: https://codeforces.com/contest/1433/problem/C
# Solution: https://codeforces.com/contest/1433/submission/96177188

tests = int(input())
for test in range(tests):
    n = int(input())
    l = [int(x) for x in input().split(" ")]
    
    if len(set(l))==1:
        print(-1)
        continue
    
    l = [0] + l + [0]
    mx = max(l)
    for i in range(1,len(l)-1):
        if l[i]==mx and ((l[i-1]<l[i] and l[i-1]!=0) or (l[i+1]<l[i] and l[i+1]!=0)):
            print(i)
            break