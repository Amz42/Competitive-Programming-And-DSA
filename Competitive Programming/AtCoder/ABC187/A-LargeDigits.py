tests = 1
# tests = int(input())
for _ in range(tests):
	a,b = input().strip(" ").split(" ")
	a = sum([int(x) for x in a])
	b = sum([int(x) for x in b])
	print(max(a,b))

"""
APPROACH:
Just simply take sum of digits of both numbers & print the greater one...
"""