# Question: https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/xor-challenge-2420f189/
# Solution: https://www.hackerearth.com/submission/56950269/

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
n = bin(int(input().strip(" ")))[2:]
a = ""
b = ""
 
flag = 1
 
for i in n:
  if i=='0':
    a += '1'
    b += '1'
  else:
    if flag:
      a += '1'
      b += '0'
      flag = 0
    else:
      b += '1'
      a += '0'
 
a = int(a,2)
b = int(b,2)
print(a*b)