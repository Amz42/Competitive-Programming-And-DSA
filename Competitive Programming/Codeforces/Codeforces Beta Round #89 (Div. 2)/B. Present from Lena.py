# Question: https://codeforces.com/contest/118/problem/B
# Solution: https://codeforces.com/contest/118/submission/79083504

n=int(input())
ans,c=[],1
for i in range(n):
    s=" "*2*(n-i)
    lis=list()
    for j in range(i+1): lis.append(str(j))
    lis2=lis[:-1]
    lis2=lis2[::-1]
    lis+=lis2
    s1=' '.join(lis)
    c+=2
    print(s+s1)
    ans.append(s+s1)
ans=ans[::-1]
lis=[]
for i in range(n+1): lis.append(str(i))
lis2=lis[:-1]
lis2=lis2[::-1]
lis+=lis2
s=" ".join(lis)
print(s)
for k in ans: print(k)