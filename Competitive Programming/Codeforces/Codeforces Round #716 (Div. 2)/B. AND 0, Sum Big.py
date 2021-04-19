# Question: https://codeforces.com/contest/1514/problem/B
# Solution: https://codeforces.com/contest/1514/submission/113548379

"""
                                                _                    _  _  ____
                                               / \   _ __ ___  ____ | || ||___ \
                                              / _ \ | '_ ` _ \|_  / | || |_ __) |
                                             / ___ \| | | | | |/ /  |__   _/ __/
                                            /_/   \_\_| |_| |_/___|    |_||_____|
"""
import sys, os.path, math
from collections import defaultdict, deque
from itertools import combinations
if os.path.exists('amz42.txt'):
  sys.stdin = open("input.txt","r")
  sys.stdout = open("output.txt","w")

""" Write from here """
for i in range(int(input())):
  n,k = [int(x) for x in input().split(" ")]
  print((n**k)%int(1e9+7))