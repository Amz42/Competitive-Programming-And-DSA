# Question: https://codeforces.com/contest/1406/problem/B
# Solution: https://codeforces.com/contest/1406/submission/92661072

for test in range(int(input())):
    n = int(input())
    l = [int(x) for x in input().split(" ")]
    l.sort()
    a = l[-5]*l[-4]*l[-3]*l[-2]*l[-1]
    b = l[0]*l[1]*l[-3]*l[-2]*l[-1]
    c = l[0]*l[1]*l[2]*l[3]*l[-1]
    
    print(max([a,b,c]))