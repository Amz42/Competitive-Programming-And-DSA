// Question: https://leetcode.com/problems/maximum-product-subarray/
// Solution: https://leetcode.com/submissions/detail/474376721/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxval, minval, answer;
        maxval = minval = answer = nums[0];
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0) swap(maxval, minval);
            
            maxval = max(nums[i], maxval * nums[i]);
            minval = min(nums[i], minval * nums[i]);
            answer = max({answer, maxval, minval});
        }
        
        return answer;
    }
};

int main(){
    return 0;
}