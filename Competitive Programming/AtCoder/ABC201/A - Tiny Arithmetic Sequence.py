# Question: https://atcoder.jp/contests/abc201/tasks/abc201_a
# Solution: https://atcoder.jp/contests/abc201/submissions/22603903

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
x,y,z = sorted([int(x) for x in input().split(" ")])
if x+z == 2*y:
  print("Yes")
else:
  print("No")