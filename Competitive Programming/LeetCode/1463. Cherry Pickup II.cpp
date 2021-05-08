// Question: https://leetcode.com/problems/cherry-pickup-ii/
// Solution: https://leetcode.com/submissions/detail/490163574/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dp[70][70][70];
    int fun(int r, int c1, int c2, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        
        if(c1<0 || c1>=m || c2<0 || c2>=m || r>=n)
            return 0;
        if(dp[r][c1][c2] != -1)
            return dp[r][c1][c2];
        
        int answer = grid[r][c1] + grid[r][c2];
        // both robots are at same points
        if(c1==c2)
            answer -= grid[r][c1];
        
        int mx = 0;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                mx = max(
                    mx,
                    fun(r+1, c1+i, c2+j, grid)
                );
            }
        }
        
        return dp[r][c1][c2] = answer + mx;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        for(int i=0;i<70;i++)
            for(int j=0;j<70;j++)
                for(int k=0;k<70;k++)
                    dp[i][j][k] = -1;
        
        return fun(0, 0, grid[0].size()-1, grid);
    }
};

int main(){
    return 0;
}