# Question: https://codeforces.com/contest/1419/problem/D2
# Solution: https://codeforces.com/contest/1419/submission/96372682

n = int(input())
l = [int(x) for x in input().split(" ")]
l.sort()
a = l[:len(l)//2]
b = l[len(l)//2:]
answer = []
x,y = 0,0
for i in range(n):
    if i%2:
        answer.append(a[x])
        x+=1
    else:
        answer.append(b[y])
        y+=1
ans = 0
for i in range(1,n-1):
    if answer[i-1]>answer[i] and answer[i]<answer[i+1]:
        ans += 1
print(ans)
print(*answer)