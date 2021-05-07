// Question: https://leetcode.com/problems/cherry-pickup/
// Solution: https://leetcode.com/submissions/detail/490149514/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dp[50][50][50];
    int fun(int r1, int c1, int c2, vector<vector<int>>& grid){
        int r2 = r1 + c1 - c2;
        int n = grid.size();
        // both workers reached at the end corner of grid
        if(r1 == n-1 && c1 == n-1)
            return grid[r1][c1];
        // either worker moved out of grid OR on thorn
        if(
            r1>=n || c1>=n || r2>=n || c2>=n ||
            grid[r1][c1]==-1 || grid[r2][c2]==-1
        )
            return INT_MIN;
        // memoized value
        if(dp[r1][c1][c2] != -1)
            return dp[r1][c1][c2];
        
        
        int answer = grid[r1][c1] + grid[r2][c2];
        
        // both workers are on same point at grid
        if(r1==r2 && c1==c2) answer -= grid[r1][c1];
        
        answer += max({
            fun(r1+1, c1, c2, grid),      // w1 moves down & w2 moves down
            fun(r1+1, c1, c2+1, grid),    // w1 moves down & w2 moves right
            fun(r1, c1+1, c2, grid),      // w1 moves right & w2 moves down
            fun(r1, c1+1, c2+1, grid)     // w1 moves right & w2 moves right
        });
        
        return dp[r1][c1][c2] = answer;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    dp[i][j][k] = -1;
        
        return max(fun(0, 0, 0, grid), 0);
    }
};

int main(){
    return 0;
}