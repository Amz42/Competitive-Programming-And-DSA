# Question: https://codeforces.com/contest/1427/problem/A
# Solution: https://codeforces.com/contest/1427/submission/95119362

for t in range(int(input())):
    n = int(input())
    a = sorted([int(x) for x in input().split(" ")])
    suma = sum(a)
    if suma==0:
        print("NO")
        continue
    
    print("YES")
    suma = 0
    for i in range(n):
        if suma + a[i] == 0:
            a = a[:i] + a[i:][::-1]
            break
        suma += a[i]
    
    suma = 0
    for i in range(n):
        if suma + a[i] == 0:
            a = a[::-1]
            break
        suma += a[i]
    
    print(*a)