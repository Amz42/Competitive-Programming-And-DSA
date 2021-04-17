# Question: https://atcoder.jp/contests/jsc2021/tasks/jsc2021_a
# Solution: https://atcoder.jp/contests/jsc2021/submissions/21806804

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
x,y,z = [int(x) for x in input().strip(" ").split(" ")]
a = (y/x)*z
if a-math.floor(a)!=0:
  print(math.floor(a))
else:
  print(int(a)-1)