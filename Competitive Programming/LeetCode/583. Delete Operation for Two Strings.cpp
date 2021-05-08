// Question: https://leetcode.com/problems/delete-operation-for-two-strings/
// Solution: https://leetcode.com/submissions/detail/490271814/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string a, string b) {
        int n = a.size();
        int m = b.size();
        int dp[n+1][m+1];
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0){
                    dp[i][j] = 0;
                    continue;
                }
                
                if(a[i-1] == b[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return (n + m - 2*dp[n][m]);
    }
};

int main(){
    return 0;
}