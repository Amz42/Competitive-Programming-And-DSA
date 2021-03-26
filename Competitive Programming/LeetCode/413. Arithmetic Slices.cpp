// Question: https://leetcode.com/problems/arithmetic-slices/
// Solution: https://leetcode.com/submissions/detail/472419450/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int dp = 0, answer = 0;
        
        for(int i = 2; i<nums.size(); i++){
            // 3 consecutive have same difference
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
                dp++; // increase chain count
                answer += dp;
            }else dp = 0;
        }
        
        return answer;
    }
};

int main(){
    Solution s = *new Solution;
    return 0;
}