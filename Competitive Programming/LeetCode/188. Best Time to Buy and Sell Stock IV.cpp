// Question: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// Solution: https://leetcode.com/submissions/detail/474368670/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int maxState;
    int dp[1005][205];
    int fun(vector<int>& prices, int index, int state){
        if(state==maxState || index==prices.size()) return 0;
        if(dp[index][state] != -1) return dp[index][state];
        
        int answer = max({
            fun(prices, index+1, state),
            fun(prices, index+1, state+1) +
            prices[index] * (state&1 ? -1 : +1)
        });
        
        return dp[index][state] = answer;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1,sizeof dp);
        maxState = 2*k+1;
        return fun(prices, 0, 1);
    }
};

int main(){
    return 0;
}