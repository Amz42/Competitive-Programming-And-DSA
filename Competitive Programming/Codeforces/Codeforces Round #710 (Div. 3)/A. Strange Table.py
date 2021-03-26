# Question: https://codeforces.com/contest/1506/problem/A
# Solution: https://codeforces.com/contest/1506/submission/111139267

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
for _ in range(int(input())):
  n,m,x = [int(x) for x in input().split(" ")]
  add = x//n + (1 if x%n else 0)
  row = x%n-1 if x%n else n-1
  print(row*m + add)