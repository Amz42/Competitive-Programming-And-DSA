// Question: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Solution: https://leetcode.com/submissions/detail/473979466/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int answer = 0;
        int last = prices[0];
        int n = prices.size();
        
        for(int i=1;i<n;i++){
            if(prices[i]>last){
                answer += prices[i] - last;
                last = prices[i];
            }
            
            last = min(prices[i], last);
        }
        
        return answer;
    }
};

int main(){
    return 0;
}