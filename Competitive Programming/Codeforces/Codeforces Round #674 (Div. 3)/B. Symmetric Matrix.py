# Question: https://codeforces.com/contest/1426/problem/B
# Solution: https://codeforces.com/contest/1426/submission/95390967

for _ in range(int(input())):
    n,k = [int(x) for x in input().split(" ")]
    yes = False
    for i in range(n):
        a,b = [int(x) for x in input().split(" ")]
        c,d = [int(x) for x in input().split(" ")]
        if c==b:
            yes = True
    if yes and k%2==0: print("YES")
    else: print("NO")