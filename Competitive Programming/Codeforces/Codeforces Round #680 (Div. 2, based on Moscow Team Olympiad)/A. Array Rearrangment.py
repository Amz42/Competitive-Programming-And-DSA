# Question: https://codeforces.com/contest/1445/problem/A
# Solution: https://codeforces.com/contest/1445/submission/97307094

tests = int(input())
for t in range(tests):
    n,x = [int(x) for x in input().split(" ")]
    a = [int(x) for x in input().split(" ")]
    b = [int(x) for x in input().split(" ")]
    if(t!=tests-1): c = input()
    a.sort()
    b.sort(reverse=True)
    
    for i in range(n):
        if a[i]+b[i]>x:
            print("No")
            break
    else:
        print("Yes")