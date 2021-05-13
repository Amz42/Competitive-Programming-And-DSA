// Question: https://leetcode.com/problems/range-sum-query-2d-immutable/
// Solution: https://leetcode.com/submissions/detail/492719768/

#include<bits/stdc++.h>
using namespace std;

class NumMatrix {
    int dp[200][200];
    int n, m, last;
    int pref(int row, int col){
        if(row<0 || row>=n || col<0 || col>=m) return 0;
        return dp[row][col];
    }
public:
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        
        for(int i=0;i<n;i++){
            last = 0;
            for(int j=0;j<m;j++)
                last = dp[i][j] = last + matrix[i][j];
        }
        
        for(int j=0;j<m;j++){
            last = 0;
            for(int i=0;i<n;i++)
                last = dp[i][j] = last + dp[i][j];
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return (pref(row2, col2) - pref(row1-1, col2) - pref(row2, col1-1) + pref(row1-1, col1-1));
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main(){
    return 0;
}