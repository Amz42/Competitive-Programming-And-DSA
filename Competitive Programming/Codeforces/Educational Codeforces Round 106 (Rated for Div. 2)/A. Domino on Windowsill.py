# Question: https://codeforces.com/contest/1499/problem/A
# Solution: https://codeforces.com/contest/1499/submission/110328899

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
tttt = 1
tttt = int(input())
for tt in range(tttt):
    n,w1,w2 = [int(x) for x in input().split(" ")]
    w,b = [int(x) for x in input().split(" ")]

    b1 = n-w1
    b2 = n-w2
    ww = min(w1,w2)
    bb = min(b1, b2)

    ww = ww + (max(w1, w2) - ww)//2
    bb = bb + (max(b1, b2) - bb)//2

    if w<=ww and b<=bb:
        print("YES")
    else:
        print("NO")