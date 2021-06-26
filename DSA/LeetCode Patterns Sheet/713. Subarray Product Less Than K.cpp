// Question: https://leetcode.com/problems/subarray-product-less-than-k/
// Solution: https://leetcode.com/submissions/detail/500842116/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size();
        long long int prod = 1;
        int answer = 0;
        
        while(r<n){
            prod *= nums[r];
            while(l<=r && prod >= k) prod /= nums[l++];
            answer += (r-l+1);
            r++;
        }
        
        return answer;
    }
};

int main(){
  return 0;
}