// Question: https://leetcode.com/problems/find-peak-element/
// Solution: https://leetcode.com/submissions/detail/502762736/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        
        int l = 1, r = nums.size()-2;
        
        while(l<=r){
            int mid = l + (r - l) / 2;
            if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1])
                return mid;
            if(nums[mid-1] < nums[mid] && nums[mid] < nums[mid+1])
                l = mid + 1;
            else
                r = mid;
        }
        
        return l;
    }
};

int main(){
  return 0;
}