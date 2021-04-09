// Question: https://leetcode.com/problems/wildcard-matching/
// Solution: https://leetcode.com/submissions/detail/478542954/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string a, string b) {
        int n = a.size();
        int m = b.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0] = true;
        
        // if no character in string
        //     if (previous str = valid) & (current pattern char is '*') => valid
        //     else => invalid
        for(int j=1;j<=m;j++)
            dp[0][j] = (dp[0][j-1]) && (b[j-1] == '*');

        // if no char in regex then string is invalid
        for(int i=1; i<=n; i++)
            dp[i][0] = false;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                
                if(b[j-1]=='*'){
                    // if previous string is valid (We're reading current i char with '*')
                    // OR we're not reading char using '*'
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                
                else if(b[j-1]=='?'){
                    // read current i-th char using '?'
                    // OR current chars are equal
                    dp[i][j] = dp[i-1][j-1];
                }
                // both current are chars
                else{
                    // chars are equal
                    if(a[i-1] == b[j-1])
                        dp[i][j] = dp[i-1][j-1];
                    // chars not equal
                    else
                        dp[i][j] = 0;
                }
            }
        }
        return dp[n][m];
    }
};

int main(){
    return 0;
}