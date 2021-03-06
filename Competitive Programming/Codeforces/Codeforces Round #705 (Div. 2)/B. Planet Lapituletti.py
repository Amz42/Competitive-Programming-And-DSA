# Question: https://codeforces.com/contest/1493/problem/B
# Solution: https://codeforces.com/contest/1493/submission/109250271

"""
                                                _                    _  _  ____
                                               / \   _ __ ___  ____ | || ||___ \
                                              / _ \ | '_ ` _ \|_  / | || |_ __) |
                                             / ___ \| | | | | |/ /  |__   _/ __/
                                            /_/   \_\_| |_| |_/___|    |_||_____|
"""
import sys, os.path
if os.path.exists('amz42.txt'):
	sys.stdin = open("input.txt","r")
	sys.stdout = open("output.txt","w")

""" Write from here """
# h,m,a,b = 0,0,0,0

def inv(n):
    if n=='1': return '1'
    if n=='2': return '5'
    if n=='5': return '2'
    if n=='8': return '8'
    if n=='0': return '0'

def valid(a,b,h,m):
    h1,h2 = [i for i in str(a)]
    m1,m2 = [i for i in str(b)]

    l = ['3','4','6','7','9']
    if (h1 in l) or (h2 in l) or (m1 in l) or (m2 in l):
        return False
    
    if (int(inv(m2) + inv(m1)) >= h) or (int(inv(h2) + inv(h1)) >= m):
        return False
    
    return True

def inc_time(a,b,h,m):
    a = int(a)
    b = int(b)
    if b+1 >= m: a = (a + 1) % h
    b = (b+1) % m

    if a<10: a = '0' + str(a)
    else: a = str(a)

    if b<10: b = '0' + str(b)
    else: b = str(b)

    return [a,b]

test_cases = 1
test_cases = int(input())
for _ in range(test_cases):
    h,m = [int(x) for x in input().split(" ")]
    a,b = [x for x in input().split(":")]

    while True:
        if valid(a,b,h,m):
            print(a,":",b,sep="")
            break
        a,b = inc_time(a,b,h,m)