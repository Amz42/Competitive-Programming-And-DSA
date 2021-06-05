// Question: https://leetcode.com/problems/maximum-subarray/
// Solution: https://leetcode.com/submissions/detail/414544645/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, maxans = INT_MIN;
        
        for(int i=0;i<n;i++){
            sum += nums[i];
            maxans = max(maxans, sum);
            if(sum<0) sum = 0;
        }
        
        return maxans;
    }
};

int main(){
  return 0;
}