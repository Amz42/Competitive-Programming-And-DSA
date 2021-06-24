# Question: https://codeforces.com/contest/1537/problem/A

for _ in range(int(input().strip(" "))):
    n = int(input().strip(" "))
    l = sum([int(x) for x in input().strip(" ").split(" ")])
    print(1 if l<n else l-n)