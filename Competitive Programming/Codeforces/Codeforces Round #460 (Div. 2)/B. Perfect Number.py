# Question: https://codeforces.com/contest/919/problem/B
# Solution: https://codeforces.com/contest/919/submission/88812289

l = []
def fun(i):
    sm = 0
    x = i
    while i:
        sm += i%10
        i //= 10
    if sm==10:
        l.append(x)

i=19
while len(l)<10000:
    fun(i)
    i+=9
print(l[int(input())-1])