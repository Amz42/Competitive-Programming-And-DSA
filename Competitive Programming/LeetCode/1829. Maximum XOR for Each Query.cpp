// Question: https://leetcode.com/problems/maximum-xor-for-each-query/
// Solution: https://leetcode.com/contest/biweekly-contest-50/submissions/detail/481755672/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> getMaximumXor(vector<int>& v, int mxb) {
		int n = v.size();
		vector<int> answer;

		int xr = 0;
		for (auto k : v) xr ^= k;

		for (int i = 0; i < n; i++) {
			bitset<64> b, bxr(xr);

			for (int j = mxb - 1; j >= 0; j--) b[j] = !bxr[j];

			answer.push_back(b.to_ullong());
			xr ^= v[v.size() - 1];
			v.pop_back();
		}

		return answer;
	}
};

int main(){
    return 0;
}