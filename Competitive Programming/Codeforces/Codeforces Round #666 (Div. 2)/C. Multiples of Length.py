# Question: https://codeforces.com/contest/1397/problem/C
# Solution: https://codeforces.com/contest/1397/submission/91636635

n = int(input())
l = [int(x) for x in input().split(" ")]
print(1,1)
print(-1*l[0])
if n==1:
    print(1,1)
    print(0)
    print(1,1)
    print(0)
elif n==2:
    print(2,2)
    print(-1*l[1])
    print(1,2)
    print(0,0)
else:
    l[0] = 0
    print(2,n)
    for i in range(1,n):
        k = l[i]%(n)
        l[i] += k*(n-1)
        print(k*(n-1),end=" ")
    print()
    print(1,n)
    for i in l:
        print(-1*i, end=" ")