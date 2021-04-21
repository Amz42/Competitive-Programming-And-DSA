// Question: https://leetcode.com/problems/distinct-subsequences/
// (Recursive) Solution-1: https://leetcode.com/submissions/detail/483428362/
// (Iterative) Solution-2: https://leetcode.com/submissions/detail/483525102/
// (Iterative Space Optimized) Solution-3: https://leetcode.com/submissions/detail/483529844/

#include <bits/stdc++.h>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////
///////////////   Solution - 1 | (Recursive)
////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
    string SS, TT;
    int dp[1001][1001];
    int fun(int s, int t){
        if(t == -1) return 1;
        if(s == -1) return 0;
        if(dp[s][t] != -1) return dp[s][t];
        
        if(SS[s] == TT[t])
            dp[s][t] = fun(s-1, t-1) + fun(s-1, t);
        else
            dp[s][t] = fun(s-1, t);
        
        return dp[s][t];
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        memset(dp, -1, sizeof dp);
        SS = s; TT = t;
        
        return fun(n-1, m-1);
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////
///////////////   Solution - 1 | (Recursive)
////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////
///////////////   Solution - 2 | (Iterative)
////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        unsigned long dp[n+1][m+1];
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                // if main string is "", then there is always 1 way to make it
                if(j==0){
                    dp[i][j] = 1;
                    continue;
                }
                
                // if main string is something & matching string is "",
                // then there is no way to make it
                if(i==0){
                    dp[i][j] = 0;
                    continue;
                }
                
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][m];
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////
///////////////   Solution - 2 | (Iterative)
////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////
///////////////   Solution - 3 | (Iterative Space Optimized)
////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        unsigned long dp[1001] = {0};
        
        // if t = "" then it is always valid
        dp[0] = 1;
        
        for(int i=1; i<=n; i++){
            // reverse loop as we need transitions
            // of previous character of string s
            for(int j=m; j>=1; j--){
                // if t & s match here then 2 choices:
                // 1. Consider string s char for string t's current char
                // 2. Consider string s previous char for string t's current char
                if(s[i-1] == t[j-1])
                    dp[j] = dp[j-1] + dp[j];
            }
        }
        
        return dp[m];
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////
///////////////   Solution - 3 | (Iterative Space Optimized)
////////////////////////////////////////////////////////////////////////////////////////////////


int main(){
    Solution s = *new Solution();
    return 0;
}