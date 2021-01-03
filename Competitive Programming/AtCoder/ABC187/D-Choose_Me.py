n = int(input())
opponent = 0
Votes = []
for _ in range(n):
    a,b = [int(x) for x in input().split(" ")]
    opponent -= a
    Votes.append(2*a+b)

Votes.sort(reverse=True)

answer = 0
while opponent<=0:
    opponent += Votes[answer]
    answer += 1

print(answer)

"""
APPROACH:
Always try to pick the town optimally,
i.e. where your opponent has most supporters & total no. of people is maximum...

"""