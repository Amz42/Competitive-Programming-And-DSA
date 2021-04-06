// Question: https://leetcode.com/problems/coin-change/
// Solution: https://leetcode.com/submissions/detail/399977078/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int tot_coins = coins.size();
        int dp[amount+1];
        for(int i=0;i<=amount;i++) dp[i] = INT_MAX;
        dp[0] = 0;
        
        for(int i=1;i<amount+1;i++){
            // calculating for ith amount
            int ans = INT_MAX;
            
            for(int j=0;j<tot_coins;j++){
                // selected jth coin
                if(coins[j]<=i){
                    ans = min(ans , dp[i-coins[j]]);
                }
            }
            
            dp[i] = (ans==INT_MAX) ? INT_MAX : ans + 1;
        }
        
        return (dp[amount]==INT_MAX ? -1: dp[amount]);
    }
};

int main(){
    return 0;
}