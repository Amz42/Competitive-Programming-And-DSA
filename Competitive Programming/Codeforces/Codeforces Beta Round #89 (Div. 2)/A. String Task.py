# Question: https://codeforces.com/contest/118/problem/A
# Solution: https://codeforces.com/contest/118/submission/61002553

s=input()
ans=""
for i in s:
    i=i.lower()
    if i in ['a','e','i','o','u','y']:
        continue
    else:
        ans+="."+i
print(ans)