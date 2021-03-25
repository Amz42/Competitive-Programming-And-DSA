// Question: https://leetcode.com/problems/unique-binary-search-trees/
// Solution: https://leetcode.com/submissions/detail/472365595/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int dp[20] = {0};
        dp[0] = dp[1] = 1;
        
        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++) dp[i] += dp[j] * dp[i-j-1];
        }
        
        return dp[n];
    }
};

int main(){
    Solution s1 = *new Solution();
    return 0;
}