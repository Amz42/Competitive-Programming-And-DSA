// Question: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Solution: https://leetcode.com/submissions/detail/436779930/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1) return 0;
        int maxn[100005], minn[100005];
        
        minn[0] = prices[0];
        for(int i=1;i<n;i++) minn[i] = min(minn[i-1], prices[i]);
        
        maxn[n-1] = prices[n-1];
        for(int i=n-2;i>=0;i--) maxn[i] = max(maxn[i+1], prices[i]);
        
        int ans = 0;
        for(int i=0;i<n-1;i++) ans = max(ans, maxn[i+1]-minn[i]);
        
        return ans;
    }
};

//APPROACH:
// 1.Make a prefix array(minimum buy price) stating min price till that day.
// 2.Make a suffix array(maximum sell price) stating max price till that day.
// 3.For each day update the answer with maximum +ve difference of prices on that day from prefix & suffix array

int main(){
    return 0;
}