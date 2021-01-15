# Question: https://atcoder.jp/contests/abc188/tasks/abc188_c
# Solution: https://atcoder.jp/contests/abc188/submissions/19341449

n = int(input().strip(" "))
l = [int(x) for x in input().strip(" ").split(" ")]

sz = len(l)
a,b = 0,sz//2

for i in range(sz//2):
    if l[i]>l[a]:
        a = i

for i in range(sz//2,sz):
    if l[i]>l[b]:
        b = i

if l[a]>l[b]:
    print(b+1)
else:
    print(a+1)