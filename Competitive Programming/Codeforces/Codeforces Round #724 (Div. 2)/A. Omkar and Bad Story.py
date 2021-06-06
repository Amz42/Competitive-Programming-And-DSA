# Question: https://codeforces.com/contest/1536/problem/A
# Solution: https://codeforces.com/contest/1536/submission/118620794

"""
                                                _                    _  _  ____
                                               / \   _ __ ___  ____ | || ||___ \
                                              / _ \ | '_ ` _ \|_  / | || |_ __) |
                                             / ___ \| | | | | |/ /  |__   _/ __/
                                            /_/   \_\_| |_| |_/___|    |_||_____|
"""
import sys, os.path, math
from collections import defaultdict, deque
if os.path.exists('amz42.txt'):
    sys.stdin = open("input.txt","r")
    sys.stdout = open("output.txt","w")
""" Write from here """

for i in range(int(input())):
    n =int((input()))
    l = list(map(int,input().split()))
    c=0
    for i in l:
        if(i<0):c=1;
    if(c):
        print("NO")
    else:
        s = l
        k=0
        while(len(s)<300):
            k=0
            for i in s:
                for j in s:
                    if(i!=j):
                        if(abs(i-j) not in s):
                            k=1
                            s.append(abs(i-j))
            if(k==0):
                print("YES")
                print(len(s))
                print(*s)
                break
        if(k==1):
            print("NO")