# Question: https://codeforces.com/contest/1421/problem/C
# Solution: https://codeforces.com/contest/1421/submission/95889227

s = input()
l = len(s)
ans = []

ans.append(['R',l-1])
l += 1
ans.append(['R',l-1])
l += 1
ans.append(['L',l-1])
l = l + l-2
ans.append(['L',2])

print(len(ans))
for g in ans:
    print(*g)