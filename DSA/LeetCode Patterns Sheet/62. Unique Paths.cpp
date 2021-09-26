// Question: https://leetcode.com/problems/unique-paths/
// Solution: https://leetcode.com/submissions/detail/415527348/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[100][100] = {0};
        dp[0][0] = 1;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(0<=i-1) dp[i][j] += dp[i-1][j]; // top
                if(0<=j-1) dp[i][j] += dp[i][j-1]; // left
            }
        }
        
        return dp[m-1][n-1];
    }
};

int main(){
    return 0;
}