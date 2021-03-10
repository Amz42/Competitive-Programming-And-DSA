# Question: https://practice.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one4724/1
# Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=f3af5934bb0d07a71e1f94b83ce43fbb&pid=704413&user=amanguptarkg6

class Solution:
    def longestSubsequence(self, N, A):
        dp = [0]*N
        answer = 1
        for i in range(0,N):
            mx = 0
            for j in range(i):
                if abs(A[i]-A[j]) == 1:
                    mx = max(mx, dp[j])
            dp[i] = mx + 1
            answer = max(answer, dp[i])
        return answer

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        A = input().split()
        for itr in range(N):
            A[itr] = int(A[itr])
        
        ob = Solution()
        print(ob.longestSubsequence(N, A))
# } Driver Code Ends