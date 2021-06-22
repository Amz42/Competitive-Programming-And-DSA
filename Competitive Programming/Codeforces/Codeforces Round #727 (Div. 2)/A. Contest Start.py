# Question: https://codeforces.com/contest/1539/problem/A

for _ in range(int(input().strip(" "))):
    n,x,t = [int(x) for x in input().strip(" ").split(" ")]
    a = min(n-1, t//x)
    answer = a * (n-a) + (a*(a-1)//2)
    print(answer)