# Question: https://codeforces.com/contest/1430/problem/A
# Solution: https://codeforces.com/contest/1430/submission/95203057

for _ in range(int(input())):
    n = int(input())
    ans = []
    found = False
    for x in range(150):
        for y in range(205):
            sm = 7*x+5*y
            if sm>n:
                break
            if (n-sm)%3==0:
                found = True
                ans = [(n-sm)//3,y,x]
                break
        if found:
            break
    if found:
        print(*ans)
    else:
        print("-1")