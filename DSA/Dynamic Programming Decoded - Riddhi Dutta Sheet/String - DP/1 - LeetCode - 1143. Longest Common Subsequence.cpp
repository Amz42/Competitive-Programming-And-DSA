// Question: https://leetcode.com/problems/longest-common-subsequence/
// Solution: https://leetcode.com/submissions/detail/406866249/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int s1 = text1.size(), s2 = text2.size();
        int dp[1001][1001] = {0}, maxl=0;

        for(int i=0;i<=s1;i++){for(int j=0;j<=s2;j++){dp[i][j] = 0;}}

        for(int i=1;i<=s1;i++){
            for(int j=1;j<=s2;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                maxl = max(maxl,dp[i][j]);
            }
        }

        return maxl;
    }
};

int main(){
    return 0;
}