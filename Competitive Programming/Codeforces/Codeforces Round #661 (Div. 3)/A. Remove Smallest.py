# Question: https://codeforces.com/contest/1399/problem/A
# Solution: https://codeforces.com/contest/1399/submission/89081697

tests = int(input())
for t in range(tests):
    n = int(input())
    l = sorted([int(x) for x in input().split(" ")])
    for i in range(n-1):
        if abs(l[i+1]-l[i]) > 1:
            print("NO")
            break
    else:
        print("YES")