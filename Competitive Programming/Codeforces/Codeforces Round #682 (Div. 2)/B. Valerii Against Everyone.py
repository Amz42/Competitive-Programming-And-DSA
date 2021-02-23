# Question: https://codeforces.com/contest/1438/problem/B
# Solution: https://codeforces.com/contest/1438/submission/98297140

for _ in range(int(input())):
    n = int(input())
    l = [int(x) for x in input().split(" ")]
    if(len(l)>len(set(l))):
        print("YES")
    else:
        print("NO")