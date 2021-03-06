# Question: https://atcoder.jp/contests/abc194/tasks/abc194_c
# Solution: https://atcoder.jp/contests/abc194/submissions/20737873

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
n = int(input().strip(" "))
l = [int(x) for x in input().strip(" ").split(" ")]

answer = 0
sum_of_numbers = 0

for i in l:
	answer += (i**2 * (n-1)) - (2*sum_of_numbers*i)
	sum_of_numbers += i

print(answer)