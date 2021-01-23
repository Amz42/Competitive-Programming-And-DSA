# Question: https://atcoder.jp/contests/abc189/tasks/abc189_b
# Solution: https://atcoder.jp/contests/abc189/submissions/19611688

n,k = [int(x) for x in input().split(" ")]
k *= 100
drunk = 0.000000
first = -1

for i in range(n):
    x,y = [int(x) for x in input().split(" ")]
    drunk += (x*y)

    if drunk>k and first == -1:
        first = i+1

print(first)