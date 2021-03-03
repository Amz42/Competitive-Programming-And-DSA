# Question: https://codeforces.com/contest/1428/problem/A
# Solution: https://codeforces.com/contest/1428/submission/95745995

for _ in range(int(input())):
    a,b,c,d = [int(x) for x in input().split(" ")]
    if a-c==0 or b-d==0:
        print(abs(a-c)+abs(b-d))
    else:
        print(abs(a-c)+abs(b-d)+2)