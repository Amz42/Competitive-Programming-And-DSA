# Question: https://codeforces.com/contest/1517/problem/A
# Solution: https://codeforces.com/contest/1517/submission/113990505

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
l = []
i = 0
while True:
  num = 2050*(10**i)
  if(num>1e18):
    break;
  i+=1
  l.append(num)

for _ in range(int(input())):
  num = int(input().strip(" "))
  ans = 0;
  for i in range(len(l)-1, -1, -1):
    if(num>=l[i]):
      x = num//l[i]
      ans += x
      num -= l[i]*x
  if(num>0):
    print(-1)
  else:
    print(ans)