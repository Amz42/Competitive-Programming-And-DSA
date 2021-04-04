# Question: https://codeforces.com/contest/1405/problem/B
# Solution: https://codeforces.com/contest/1405/submission/92039529

for t in range(int(input())):
    n = int(input())
    l = [int(x) for x in input().split(" ")]
    
    p = 0
    n = 0
    for i in l:
        if i<0:
            x = min([p,-1*i])
            i += x
            p -= x
            n += i
        else:
            p += i
    print(-1*n)