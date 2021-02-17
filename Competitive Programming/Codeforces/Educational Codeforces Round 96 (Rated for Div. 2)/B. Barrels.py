# Question: https://codeforces.com/contest/1430/problem/B
# Solution: https://codeforces.com/contest/1430/submission/95213615

for _ in range(int(input())):
    n,k = [int(x) for x in input().split(" ")]
    a = [int(x) for x in input().split(" ")]
    a.sort(reverse=True)
    print(sum(a[1:k+1]) + a[0])