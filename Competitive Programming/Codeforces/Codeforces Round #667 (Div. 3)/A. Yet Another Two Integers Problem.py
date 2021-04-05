# Question: https://codeforces.com/contest/1409/problem/A
# Solution: https://codeforces.com/contest/1409/submission/91809068

for t in range(int(input())):
    a,b = map(int, input().split(" "))
    if a>b: a,b = b,a
    diff = b-a
    ans = 0
    for i in range(10,0,-1):
        ans += diff//i
        diff = diff%i
    print(ans)