# Question: https://atcoder.jp/contests/jsc2021/tasks/jsc2021_b
# Solution: https://atcoder.jp/contests/jsc2021/submissions/21809268

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
d = dict()
n,m = [int(x) for x in input().split(" ")]
l =  [int(x) for x in input().split(" ")]
l = l + [int(x) for x in input().split(" ")]

for i in l:
  if i not in d.keys(): d[i] = 0;
  d[i] += 1


answer = []
for i in d.keys():
  if d[i] == 1:
    answer.append(i)
answer.sort()
print(*answer)