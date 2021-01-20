// Question: https://leetcode.com/problems/maximal-square/
// Solution: https://leetcode.com/submissions/detail/445373776/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& samples) {
        int n = samples.size();
        if (n == 0) return 0;
        int m = samples[0].size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int answer = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (samples[i - 1][j - 1] == '1') {
                    dp[i][j] = 1 + min({
                        dp[i - 1][j],
                        dp[i - 1][j - 1],
                        dp[i][j - 1]
                    });
                    answer = max(answer, dp[i][j]);
                }
            }
        }

        return (answer * answer);
    }
};