# Question: https://codeforces.com/contest/1435/problem/A
# Solution: https://codeforces.com/contest/1435/submission/96652626

for _ in range(int(input())):
    n = int(input())
    l = [int(x) for x in input().split(" ")]
    ans = l[::-1]
    for i in range(n//2):
        ans[i] *= -1
    print(*ans)