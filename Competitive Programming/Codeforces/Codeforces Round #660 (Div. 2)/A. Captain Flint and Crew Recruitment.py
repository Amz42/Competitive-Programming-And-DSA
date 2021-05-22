# Question: https://codeforces.com/contest/1388/problem/A
# Solution: https://codeforces.com/contest/1388/submission/88532030

tests = int(input())
for t in range(tests):
    n = int(input())
    if n<31:
        print("NO")
    else:
        print("YES")
        if n==36: print("5 6 10 15")
        elif n==40: print("6 9 10 15")
        elif n==44: print("6 7 10 21")
        else: print(6,10,14,n-30)