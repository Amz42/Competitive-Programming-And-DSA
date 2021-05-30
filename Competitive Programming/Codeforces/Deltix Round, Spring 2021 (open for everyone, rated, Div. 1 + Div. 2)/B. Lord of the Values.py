# Question: https://codeforces.com/contest/1523/problem/B
# Solution: https://codeforces.com/contest/1523/submission/117929838

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
for _ in range(int(input().strip(" "))):
  n = int(input().strip(" "))
  l = [int(x) for x in input().strip(" ").split(" ")]
  print((n//2)*6)
  for i in range(1,n,2):
    print(1, i, i+1)
    print(2, i, i+1)
    print(2, i, i+1)
    print(1, i, i+1)
    print(2, i, i+1)
    print(2, i, i+1)