# Question: https://codeforces.com/contest/1436/problem/C
# Solution: https://codeforces.com/contest/1436/submission/96604907

n,x,p = [int(x) for x in input().split(" ")]
a = [-1 for x in range(n)]
M = int(1e9)+7
l,r = 0,n

sm = x-1
gr = n-x

while l<r:
    mid = (l+r)//2
    # if mid==p:
    #     a[mid] = 1
    #     break
    if mid<=p:
        if mid==p:
            a[mid] = 1
        else:
            a[mid] = sm
            sm -= 1
            sm = max([0,sm])
        l = mid+1
    elif mid>p:
        a[mid] = gr
        gr -= 1
        gr = max([0,gr])
        r = mid
answer = 1
rem = sm+gr
# print(a)
for i in range(n):
    if a[i]==-1:
        answer *= rem
        answer %= M
        rem -= 1
    else:
        answer *= a[i]
        answer %= M

print(answer)