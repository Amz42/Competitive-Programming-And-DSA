# Question: https://atcoder.jp/contests/abc195/tasks/abc195_a
# Solution: https://atcoder.jp/contests/abc195/submissions/20872080

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
M,H = [int(x) for x in input().split(" ")]
if H%M: print("No")
else: print("Yes")