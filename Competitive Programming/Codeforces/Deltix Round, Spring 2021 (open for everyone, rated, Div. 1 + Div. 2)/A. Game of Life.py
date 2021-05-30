# Question: https://codeforces.com/contest/1523/problem/A
# Solution: https://codeforces.com/contest/1523/submission/117927359

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
  n,k = [int(x) for x in input().strip(" ").split(" ")]
  s = [int(x) for x in input().strip(" ")]

  if 1 not in s:
    print(*s, sep="")
    continue

  f = s.index(1)
  moves = k
  i = f-1
  while moves>0 and i>=0:
    s[i] = 1
    i -= 1
    moves -= 1
  
  l = n - s[::-1].index(1) - 1;
  moves = k
  i = l+1
  while moves>0 and i<n:
    s[i] = 1
    i += 1
    moves -= 1

  i = f
  while i<l:
    while i<l and s[i] == 1: i += 1
    j = i
    while j<l and s[j] == 0: j += 1
    x,y = i,j-1

    moves = k
    while x<y and moves>0:
      s[x] = 1
      s[y] = 1
      x += 1
      y -= 1
      moves -= 1

    i = j

  print(*s, sep="")