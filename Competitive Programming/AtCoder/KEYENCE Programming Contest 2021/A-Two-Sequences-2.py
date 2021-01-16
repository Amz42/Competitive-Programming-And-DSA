# Question: https://atcoder.jp/contests/keyence2021/tasks/keyence2021_a
# Solution: https://atcoder.jp/contests/keyence2021/submissions/19464582

n = int(input().strip(" "))
a = [int(x) for x in input().split(" ")]
b = [int(x) for x in input().split(" ")]

ml = [a[0]*b[0]]

for i in range(1,n):
    a[i] = max(a[i], a[i-1])
    ml += [a[i]*b[i]]

for i in range(1,n):
    ml[i] = max(ml[i],ml[i-1])

print(*ml)