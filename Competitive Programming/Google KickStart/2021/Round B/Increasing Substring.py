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
  n = int(input())
  s = input()
  print("Case #",_+1,": ", end="", sep="")
  last = 1
  for i in range(n):
    if i==0:
      print("1 ",end="")
    else:
      if s[i-1] < s[i]:
        print(last+1,end=" ")
        last += 1
      else:
        print(1,end=" ")
        last = 1
  print()