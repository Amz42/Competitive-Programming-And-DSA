# Question: https://codeforces.com/contest/427/problem/A
# Solution: https://codeforces.com/contest/427/submission/75798455

n=int(input())
l=[int(x) for x in input().split(" ")]
count,sm=0,0
for x in l:
    sm+=x
    if sm<0:
        count+=1
        sm=0
print(count)