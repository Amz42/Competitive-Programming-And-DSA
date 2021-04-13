// Question: https://leetcode.com/problems/count-square-submatrices-with-all-ones/
// Solution: https://leetcode.com/submissions/detail/480159974/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        // each cell of dp tells the total no. of squares with
        // diff sizes having their bottom-right corner over it
        
        // Tip: we can apply operations on given matrix
        // itself to avoid using explicit dp storage
        
        int dp[n+1][m+1];
        int answer = 0;
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0){
                    dp[i][j] = 0;
                    continue;
                }
                
                if(matrix[i-1][j-1]==1){
                    // 1: for self being 1  AND
                    // min of left, top & top-left gives grid with size>1
                    dp[i][j] = 1 + min({
                        dp[i-1][j],
                        dp[i-1][j-1],
                        dp[i][j-1]
                    });
                }else
                    dp[i][j] = 0;
                answer += dp[i][j];
            }
        }
        
        return answer;
    }
};

int main(){
    return 0;
}