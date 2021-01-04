# Question: https://codeforces.com/contest/1472/problem/B
# Solution: https://codeforces.com/contest/1472/submission/103226516

tests = int(input())
for _ in range(tests):
    n = int(input())
    l = [int(x) for x in input().strip(" ").split(" ")]
    A = l.count(1)
    B = l.count(2)
    
    if(A%2==1): print("NO")
    elif(B%2==1 and A<2): print("NO")
    else: print("YES")