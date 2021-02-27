# Question: https://codeforces.com/contest/1436/problem/B
# Solution: https://codeforces.com/contest/1436/submission/96557699

def isPrime(num):
	if (num <= 1): return False
	if (num <= 3): return True
	if (num % 2 == 0 or num % 3 == 0): return False
	i = 5
	while(i * i <= num) : 
		if (num % i == 0 or num % (i + 2) == 0): return False
		i = i + 6
	return True

for _ in range(int(input())):
    n = int(input())
    
    if isPrime(n):
        l = [[1 for j in range(n)] for i in range(n)]
    else:
        l = [[1 if i==j or i+j==n-1 else 0 for j in range(n)] for i in range(n)]
        if n%2==1:
            #odd num
            mid = n//2
            i,j=mid,mid
            l[i+1][j] = 1
            l[i][j-1] = 1
    
    for i in range(n):
        print(*l[i])