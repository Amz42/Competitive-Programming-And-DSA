# Question: https://codeforces.com/contest/1525/problem/A
# Solution: https://codeforces.com/contest/1525/submission/116327529

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
for _ in range(int(input())):
  k = int(input().strip(" "))

  e = 1
  w = 0
  step = 1
  while (e*100)/(e+w) != k:
    if (e*100)/(e+w) < k:
      e += 1
    else:
      w += 1
    step += 1
  print(step)