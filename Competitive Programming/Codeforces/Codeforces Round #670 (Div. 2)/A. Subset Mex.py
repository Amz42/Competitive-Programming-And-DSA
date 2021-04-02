# Question: https://codeforces.com/contest/1406/problem/A
# Solution: https://codeforces.com/contest/1406/submission/92660794

for test in range(int(input())):
    n = int(input())
    l = [int(x) for x in input().split(" ")]
    freq = [0 for i in range(0,101)]
    for i in l:
        freq[i] += 1
    ans = 0
    for i in range(101):
        if freq[i]==0:
            ans = 2*i
            break
        elif freq[i]==1:
            ans += i
            for j in range(i+1,101):
                if freq[j] in [0]:
                    ans += j
                    break
            break
    print(ans)