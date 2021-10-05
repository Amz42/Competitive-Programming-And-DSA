// Question: https://leetcode.com/problems/unique-paths/
// Solution-1: https://leetcode.com/submissions/detail/415527348/
// Solution-2: https://leetcode.com/submissions/detail/566351213/

#include <bits/stdc++.h>
using namespace std;

class Solution1 {
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

class Solution2 {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1) return 1;
        if(m < n) swap(m,n);
        
        m--, n--;
        
        long long int answer = 1;
        int j = 1;
        for(int i = m + 1; i<=m+n; i++, j++)
            answer = (answer * i) / j;
        
        return (int)answer;
    }
};

int main(){
    return 0;
}