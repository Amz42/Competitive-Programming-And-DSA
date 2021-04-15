# Question: https://codeforces.com/contest/777/problem/A
# Solution: https://codeforces.com/contest/777/submission/75070290

a1="102"
a2="120"
a3="210"
a4="201"
a5="021"
n=int(input())
x=int(input())
if n%6==1: print(a1[x])
elif n%6==2: print(a2[x])
elif n%6==3: print(a3[x])
elif n%6==4: print(a4[x])
elif n%6==5: print(a5[x])
else: print(x)