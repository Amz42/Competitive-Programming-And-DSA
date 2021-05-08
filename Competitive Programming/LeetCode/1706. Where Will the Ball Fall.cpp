// Question: https://leetcode.com/problems/where-will-the-ball-fall/
// Solution: https://leetcode.com/submissions/detail/490230807/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m, 1));
        
        for(int i=0;i<m;i++) dp[n][i] = i;
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){ // deflect right
                    if(j+1==m || grid[i][j+1]==-1) dp[i][j] = -1;
                    else dp[i][j] = dp[i+1][j+1];
                }else{ // deflect left
                    if(j-1<0 || grid[i][j-1]==1) dp[i][j] = -1;
                    else dp[i][j] = dp[i+1][j-1];
                }
            }
        }
        
        return dp[0];
    }
};

int main(){
    return 0;
}