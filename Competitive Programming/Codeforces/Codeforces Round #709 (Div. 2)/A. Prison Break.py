# Question: https://codeforces.com/contest/1484/problem/A
# Solution: https://codeforces.com/contest/1484/submission/110629584

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
  n,m = [int(x) for x in input().split(" ")]
  print(n*m)