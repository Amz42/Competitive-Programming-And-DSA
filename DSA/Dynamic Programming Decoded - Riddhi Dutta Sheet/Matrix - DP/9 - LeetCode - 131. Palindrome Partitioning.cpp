// Question: https://leetcode.com/problems/palindrome-partitioning/
// Solution: https://leetcode.com/submissions/detail/483136399/

#include <bits/stdc++.h>
using namespace std;

class Solution {	
	int dp[20][20];
	bool isPalindrome(int l, int r, string& S) {
		if (dp[l][r] != -1) return dp[l][r];
        int x = l;
        int y = r;
		while (l < r) {
			if (S[l] != S[r]) return dp[x][y] = false;
            l++, r--;
		}

		return dp[x][y] = true;
	}

	void dfs(int index, vector<string>& v, vector<vector<string>>& answer, string& S) {
		if (index == S.size()) {
			answer.push_back(v);
			return;
		}

		for (int len = 1; len + index <= S.size(); len++) {
			if (isPalindrome(index, index + len - 1, S)) {
                string str = S.substr(index, len);
				v.push_back(str);
				dfs(index + len, v, answer, S);
				v.pop_back();
			}
		}
	}
public:
	vector<vector<string>> partition(string s) {
		memset(dp, -1, sizeof dp);

        vector<vector<string>> answer;
		vector<string> v;
		dfs(0, v, answer, s);

		return answer;
	}
};

int main(){
    return 0;
}