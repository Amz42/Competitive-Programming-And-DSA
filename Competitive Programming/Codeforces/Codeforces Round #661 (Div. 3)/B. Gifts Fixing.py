# Question: https://codeforces.com/contest/1399/problem/B
# Solution: https://codeforces.com/contest/1399/submission/89081599

tests = int(input())
for t in range(tests):
    n = int(input())
    candy = list(map(int,input().split(" ")))
    orange = list(map(int,input().split(" ")))
    mincandy = min(candy)
    minorange = min(orange)
    ans = 0
    for i in range(n):
        a = candy[i]-mincandy
        b = orange[i]-minorange
        ans += min([a,b]) + abs(a-b)
    print(ans)