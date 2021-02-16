# Question: https://codeforces.com/contest/1437/problem/A
# Solution: https://codeforces.com/contest/1437/submission/99810914

import sys
import time
import math

OFFLINE = 0

if OFFLINE: sys.stdin, sys.stdout = open('input.txt', 'r'), open('output.txt', 'w')




def main():
	tests = 1
	tests = int(input().strip(" "))
	for _ in range(tests):
		l,r = sorted([int(x) for x in input().split(" ")])
		print(["NO","YES"][bool(l>=(r+1)/2)])



if __name__ == "__main__":
	if OFFLINE: start_time = time.time()
	
	main()
	
	if OFFLINE: print("Execution Time: %s secs" % (time.time() - start_time), file=sys.stderr)