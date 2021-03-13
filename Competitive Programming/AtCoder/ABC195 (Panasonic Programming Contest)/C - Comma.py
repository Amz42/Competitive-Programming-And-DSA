# Question: https://atcoder.jp/contests/abc195/tasks/abc195_c
# Solution: https://atcoder.jp/contests/abc195/submissions/20883162

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
n = int(input())
x = 1000
i = 1
answer = 0
while n>=x:
	answer += i * (min(n,x*1000)-x) + 1
	x*=1000
	i+=1
print(answer)