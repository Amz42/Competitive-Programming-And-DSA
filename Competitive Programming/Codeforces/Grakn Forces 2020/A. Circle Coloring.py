# Question: https://codeforces.com/contest/1408/problem/A
# Solution: https://codeforces.com/contest/1408/submission/94306684

for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split(" ")]
    b = [int(x) for x in input().split(" ")]
    c = [int(x) for x in input().split(" ")]
    ans = [a[0]]
    last = a[0]
    for i in range(1,n-1):
        if a[i]!=last:
            ans.append(a[i])
            last = a[i]
        elif b[i]!=last:
            ans.append(b[i])
            last = b[i]
        elif c[i]!=last:
            ans.append(c[i])
            last = c[i]
    last = ans[0]
    if a[n-1]!=last and a[n-1]!=ans[-1]: ans.append(a[n-1])
    elif b[n-1]!=last and b[n-1]!=ans[-1]: ans.append(b[n-1])
    elif c[n-1]!=last and c[n-1]!=ans[-1]: ans.append(c[n-1])
    print(*ans)