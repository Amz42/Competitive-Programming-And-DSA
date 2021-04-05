# Question: https://codeforces.com/contest/1409/problem/B
# Solution: https://codeforces.com/contest/1409/submission/91867674

for t in range(int(input())):
    a,b,x,y,n = map(int,input().split(" "))
    
    # on a
    ka = min([a-x, n])
    kan = n - ka
    kb = min([b-y,kan])
    ans1 = (a-ka)*(b-kb)
    
    # on b
    kb = min([b-y,n])
    kbn = n - kb
    ka = min([a-x, kbn])
    ans2 = (a-ka)*(b-kb)
    
    print(min([ans1,ans2]))