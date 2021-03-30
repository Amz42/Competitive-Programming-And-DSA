// Question: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// (D&C) Solution1: https://leetcode.com/submissions/detail/473997213/
// (DP)  Solution2: https://leetcode.com/submissions/detail/474004138/

#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////     Solution 1 | Diveide & Conquer Approach
//////////////////////////////////////////////////////////////////////////////////////////////////
// Divide & Conquer Approach
class Solution1 {
	vector<int> fun(vector<int>& v, int n, bool ForLeft) {
		vector<int> a(n); a[0] = 0;
		int mn, mx; mn = mx = v[0];

		for (int i = 1; i < n; i++) {
			a[i] = max(
			           a[i - 1],
			           (ForLeft ? v[i] - mn : mx - v[i])
			       );
			mn = min(mn, v[i]);
			mx = max(mx, v[i]);
		}

		return a;
	}
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n == 1) return 0;

		auto a1 = fun(prices, n, true); // for first transaction
		reverse(prices.begin(), prices.end());
		auto a2 = fun(prices, n, false); // for second transaction
		reverse(a2.begin(), a2.end());

		int answer = 0;
		for (int i = 1; i < n; i++) answer = max(answer, a1[i - 1] + a2[i]);

		return max({answer, a1[n - 1], a2[0]});
	}
};
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////     Solution 1 | Diveide & Conquer Approach
//////////////////////////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////     Solution 2 | DP Approach
//////////////////////////////////////////////////////////////////////////////////////////////////
class Solution2 {
    int dp[100001][5];
    int n;
    
    int fun(vector<int>& prices, int day, int state){
        if(day==n || state==5) return 0;
        if(dp[day][state] != -1) return dp[day][state];
        
        int profit = max(
            fun(prices, day+1, state), // skip this day
            fun(prices, day+1, state+1) +
            prices[day] * (state&1 ? -1/*BUY*/ : +1/*SELL*/)
        );
        
        return dp[day][state] = profit;
    }
    
public:
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof dp);
        n = prices.size();
        
        return fun(prices, 0, 1);
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////     Solution 2 | DP Approach
//////////////////////////////////////////////////////////////////////////////////////////////////



int main(){
    return 0;
}