// Question: https://leetcode.com/problems/regular-expression-matching/
// Solution: https://leetcode.com/submissions/detail/479656560/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int n = p.size();
		int m = s.size();

		bool dp[n + 1][m + 1];
        
        // 0 length string & regex is always valid
        dp[0][0] = 1;
        
        // if no char in regex then it can never match the string
		for (int j = 1; j <= m; j++) dp[0][j] = 0;
        
        // setting the acceptance of regex for empty string 
        // on the bais of '*' available
		for (int i = 1; i <= n; i++) {
			if (p[i - 1] == '*') dp[i][0] = dp[i - 2][0];
			else dp[i][0] = false; // it's non '*' char so it'll not match
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = false; // by default

                // if chars match or regex char is '.'
				if (s[j - 1] == p[i - 1] || p[i - 1] == '.') {
                    // dependent on previous strings
					dp[i][j] = dp[i - 1][j - 1];
				} else if (p[i - 1] == '*') {
					dp[i][j] = (
                        // ignoring '*' & its char
                        dp[i - 2][j] ||             
                        
                        // using '*'
                        (
                            // either prev char match OR it's '.'
                            ( s[j - 1] == p[i - 2] || p[i - 2] == '.' ) &&
                            // AND prev string sholud be valid
                            dp[i][j - 1]           
                        )
                    );
				}
			}
		}

		return dp[n][m];
	}
};

int main(){
    return 0;
}