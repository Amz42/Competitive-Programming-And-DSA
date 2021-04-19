# Question: https://codeforces.com/contest/1514/problem/A
# Solution: https://codeforces.com/contest/1514/submission/113545615

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

  for i in l:
    sq = int(i**0.5)
    if sq*sq != i:
      print("YES")
      break
  else:
    print("NO")