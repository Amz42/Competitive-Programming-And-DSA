# Question: https://codeforces.com/contest/1428/problem/C
# Solution: https://codeforces.com/contest/1428/submission/95761292

for _ in range(int(input())):
    s = input()
    a=0
    b=0
    
    for i in s:
        if i=='A':
            a += 1
        else:
            if a>0:
                a -= 1
            else:
                b += 1
    print(a+(b%2))