// Question: https://leetcode.com/problems/perfect-squares/
// Solution: https://leetcode.com/submissions/detail/472414124/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX); dp[0] = 0;
        
        for(int i=0;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                dp[i] = min(dp[i], dp[i-j*j]+1);
            }
        }
        
        return dp[n];
    }
};

int main(){
    Solution s = *new Solution();
    return 0;
}