// Question: https://leetcode.com/problems/longest-palindromic-subsequence/
// (Iterative) Solution1: https://leetcode.com/submissions/detail/479667766/
// (Recursive) Solution2: https://leetcode.com/submissions/detail/479669978/


#include<bits/stdc++.h>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////
////////////////                    Solution 1 | Iterative
////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int dp[1001][1001];
        memset(dp, 0, sizeof dp);
        
        for(int i=0;i<=n;i++){ // length
            for(int j=i;j<=n;j++){ // index
                // if length is 0 => lps = 0
                // if length is 1 => lps = 1
                if(i<=1){
                    dp[i][j] = i;
                    continue;
                }
                
                if(s[j-i] == s[j-1]){
                    // (left char) + (lps of mid string) + (right char)
                    dp[i][j] = 2 + dp[i-2][j-1];
                }else{
                    // max(leave left char , leave right char)
                    dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]);
                }
            }
        }
        
        return dp[n][n];
    }
};
////////////////////////////////////////////////////////////////////////////////////////
////////////////                    Solution 1 | Iterative
////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////
////////////////                    Solution 2 | Recursive
////////////////////////////////////////////////////////////////////////////////////////
class Solution {
    string S;
    int dp[1001][1001];
    int fun(int i, int j){
        if(i==j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(S[i]==S[j]){
            if(i+1 == j) dp[i][j] = 2;
            else dp[i][j] = 2 + fun(i+1, j-1);
        }else{
            dp[i][j] = max(
                fun(i+1, j),
                fun(i, j-1)
            );
        }
        
        return dp[i][j];
    }
public:
    int longestPalindromeSubseq(string s) {
        memset(dp, -1, sizeof(dp));
        S = s;
        return fun(0, s.size()-1);
    }
};
////////////////////////////////////////////////////////////////////////////////////////
////////////////                    Solution 2 | Recursive
////////////////////////////////////////////////////////////////////////////////////////

int main(){
    return 0;
}