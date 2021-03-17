# Question: https://codeforces.com/contest/1497/problem/C2
# Solution: https://codeforces.com/contest/1497/submission/110253330

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
test_cases = int(input())
for _ in range(test_cases):
  n,k = [int(x) for x in input().split(" ")]

  for i in range(k-3):
    print(1,end=" ")
    n -= 1
  
  if n&1:
    print(1, n//2, n//2)
  else:
    if (n//2)&1:
      print(n//2-1, n//2-1, 2)
    else:
      print(n//2,n//4,n//4)