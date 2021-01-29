# Question: https://codeforces.com/contest/1476/problem/B
# Solution: https://codeforces.com/contest/1476/submission/105891935

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
test_cases = int(input())
for tttt in range(test_cases):
    N,K = map(int,input().split(" "))
    arr = list(map(int,input().split(" ")))
    present, cf, ans = 0,arr[0],0
    
    for g in range(1,N):
        present = arr[g]

        if (present*100)/cf > K:
            change = math.ceil((100*present)/K - cf)
            cf += change
            ans += change
        cf += arr[g]
    print(ans)