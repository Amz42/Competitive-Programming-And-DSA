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
for t in range(int(input().strip(" "))):
  n,k = [int(x) for x in input().split(" ")]
  s = input()
  count = 0
  for i in range(n//2):
    if s[i] != s[n-i-1]:
      count += 1
  print("Case #",t+1,": ",abs(k-count), sep="")