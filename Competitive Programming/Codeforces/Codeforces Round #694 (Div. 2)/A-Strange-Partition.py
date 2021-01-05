# Question: https://codeforces.com/contest/1471/problem/A
# Solution: https://codeforces.com/contest/1471/submission/103464686

for _ in range(int(input())):
    mini,maxi = 0,0
    n,x = [int(x) for x in input().split(" ")]
    l = [int(x) for x in input().split(" ")]
    sm = sum(l)
    mini = sm//x + (1 if sm%x else 0)
    for i in l: maxi += i//x + (1 if i%x else 0)
    print(mini,maxi)