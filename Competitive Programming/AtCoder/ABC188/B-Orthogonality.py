# Question: https://atcoder.jp/contests/abc188/tasks/abc188_b
# Solution: https://atcoder.jp/contests/abc188/submissions/19321642

n = int(input().strip(" "))
a = [int(x) for x in input().strip(" ").split(" ")]
b = [int(x) for x in input().strip(" ").split(" ")]

answer = 0

for i in range(n):
    answer += a[i]*b[i]

print("Yes" if answer==0 else "No" )