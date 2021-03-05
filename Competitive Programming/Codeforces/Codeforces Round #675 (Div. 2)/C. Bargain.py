# Question: https://codeforces.com/contest/1422/problem/C
# Solution: https://codeforces.com/contest/1422/submission/96312289

string = input().strip(" ")[::-1]
answer = 0
MOD = int(1e9+7)
right_combs = 0
l = len(string)

for i in range(l):
    digit = int(string[i])
    num_left_elements = l-i-1
    
    # for left substring removal & combinations
    answer += (num_left_elements*(num_left_elements+1))//2 * digit * pow(10, i, MOD)
    
    # for right substring removal & combinations
    answer += (right_combs * digit)
    
    answer %= MOD
    
    right_combs += (i+1) * pow(10,i, MOD)
    right_combs %= MOD
    
else:
    print(answer)