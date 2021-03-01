# Question: https://codeforces.com/contest/1421/problem/A
# Solution: https://codeforces.com/contest/1421/submission/95863107

for _ in range(int(input())):
    a,b = [int(x) for x in input().split(" ")]
    print((a|b) - (a&b))