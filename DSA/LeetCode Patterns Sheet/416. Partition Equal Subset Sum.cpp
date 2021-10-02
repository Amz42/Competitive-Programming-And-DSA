// Question: https://leetcode.com/problems/partition-equal-subset-sum/
// Solution: https://leetcode.com/submissions/detail/477358785/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0; for(int i=0;i<n;i++) sum += nums[i];
        if(sum&1) return false;
        
        sum >>= 1;
        bool dp[20001] = {0}; dp[0] = true;
        
        for(int i=0;i<n;i++){
            for(int j=sum;j>0;j--){
                if(nums[i]>j) break;
                if(dp[j-nums[i]]) dp[j] = true;
            }
        }
        
        return dp[sum];
    }
};

int main(){
    return 0;
}