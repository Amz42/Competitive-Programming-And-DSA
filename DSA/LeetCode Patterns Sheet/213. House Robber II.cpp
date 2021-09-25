// Question: https://leetcode.com/problems/house-robber-ii/
// Solution: https://leetcode.com/submissions/detail/473015103/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int fun(vector<int>& nums){
        int n = nums.size();
        if(n==1) return nums[0];
        int dp[100]; dp[0] = nums[0]; dp[1] = max(nums[0], nums[1]);
        
        for(int i=2;i<n;i++) dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        return dp[n-1];
    }
    
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int first = nums[0];
        
        // to ignore first house
        nums[0] = 0;
        int answer1 = fun(nums);
        
        // to ignore last house
        nums[0] = first; nums[n-1] = 0;
        int answer2 = fun(nums);
        
        return max(answer1, answer2);
    }
};

int main(){
    Solution s = *new Solution();
    return 0;
}