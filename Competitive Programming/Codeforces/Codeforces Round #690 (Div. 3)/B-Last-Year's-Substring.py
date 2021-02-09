# Question: https://codeforces.com/contest/1462/problem/B
# Solution: https://codeforces.com/contest/1462/submission/101278071

tests = int(input())
for _ in range(tests):
    n = int(input())
    s = input()

    answer = 0

    if (s[:4]=='2020' or s[n-4:] == '2020') or (s[0]=='2' and s[n-3:]=='020') or (s[:2]=='20' and s[n-2:]=='20') or (s[:3]=='202' and s[n-1:]=='0'):
        answer = 1
    
    if(answer): print("YES")
    else: print("NO")