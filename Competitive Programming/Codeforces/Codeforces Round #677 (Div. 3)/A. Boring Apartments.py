# Question: https://codeforces.com/contest/1433/problem/A
# Solution: https://codeforces.com/contest/1433/submission/96174972

tests = int(input())
for test in range(tests):
    s = input().strip()
    print(((int(s[0])-1)*10 + (len(s)*(len(s)+1))//2))