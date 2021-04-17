# Question: https://atcoder.jp/contests/jsc2021/tasks/jsc2021_c
# Solution: https://atcoder.jp/contests/jsc2021/submissions/21815235

"""
                                                _                    _  _  ____
                                               / \   _ __ ___  ____ | || ||___ \
                                              / _ \ | '_ ` _ \|_  / | || |_ __) |
                                             / ___ \| | | | | |/ /  |__   _/ __/
                                            /_/   \_\_| |_| |_/___|    |_||_____|
"""
import sys, os.path
if os.path.exists('amz42.txt'):
  sys.stdin = open("input.txt","r")
  sys.stdout = open("output.txt","w")

""" Write from here """
import math
a,b = [int(x) for x in input().split(" ")]

answer = 1;
for i in range(1,b+1):
  x = math.ceil(a/i) 
  y = math.floor(b/i)
  if x < y and x*i>=a and y*i<=b:
    answer = i;
print(answer)