## Coding Ninja - Buy and Sell Stock

### [Question](https://www.codingninjas.com/codestudio/problems/buy-and-sell-stock_1071012?leftPanelTab=0)

### C++ Solution
```c++
int fun(
	int day, int state, 
	vector<int>& prices, 
	vector<vector<int>>& dp
){
	if(day == prices.size() || state == 5) return 0;
	if(dp[day][state] != -1) return dp[day][state];
	
	int maxProfit = max(
		// No Transaction
		fun(day+1, state, prices, dp), 
		// Do Transaction
		fun(day+1, state+1, prices, dp) +
		prices[day] * (state & 1
			? +1 // SELL (Money will increase)
			: -1 // BUY (Money will reduce)
		)
	);
	
	return dp[day][state] = maxProfit;
}

int maxProfit(vector<int>& prices, int n) {
	vector<vector<int>> dp(prices.size(), vector<int>(5, -1));
	return fun(0, 0, prices, dp);
}
```