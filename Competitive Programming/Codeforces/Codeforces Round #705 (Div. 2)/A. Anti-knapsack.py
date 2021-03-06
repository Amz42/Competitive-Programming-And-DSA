# Question: https://codeforces.com/contest/1493/problem/A
# Solution: https://codeforces.com/contest/1493/submission/109235395

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
    n,k = map(int, input().strip(" ").split(" "))
    answer = []
    for i in range((k+1)//2,k): answer += [i]
    for i in range(k+1,n+1): answer.append(i)
    print(len(answer))
    for i in answer: print(i,end=" ")
    print()