# Question: https://codeforces.com/contest/1527/problem/A
# Solution: https://codeforces.com/contest/1527/submission/116763168

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
  nd = 1
  while (nd*2 <= n):
    nd = nd * 2
  print(nd-1)