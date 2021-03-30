// Question: https://leetcode.com/problems/decode-ways/
// Solution: https://leetcode.com/submissions/detail/473969734/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int dp[105] = {0};
        dp[0] = 1;
        
        unordered_map<string, bool> valid_string;
        for(int i=1;i<=26;i++) valid_string[to_string(i)] = true;
        
        for(int i=1;i<=n;i++){ // position
            for(int j=1;j<=min(2,i);j++){ // length
                if( valid_string[s.substr(i-j,j)] && dp[i-j] )
                    dp[i] += dp[i-j];
            }
        }
        
        return dp[n];
    }
};

int main(){
    Solution s = *new Solution();
    return 0;
}