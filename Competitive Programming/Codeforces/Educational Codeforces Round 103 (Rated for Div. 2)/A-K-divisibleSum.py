# Question: https://codeforces.com/contest/1476/problem/A
# Solution: https://codeforces.com/contest/1476/submission/105859732

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
for tttt in range(test_cases):
    N,K = map(int, input().split(" "))
    if K<N: K *= (N//K + (1 if N%K else 0))
    print(K//N + (1 if K%N else 0))