// Question: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Solution: https://leetcode.com/submissions/detail/502786818/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        
        while(l <= r){
            while(l < r && nums[l] == nums[l+1]) l++;
            while(l < r && nums[r-1] == nums[r]) r--;
            
            int mid = l + (r - l) / 2;
            if(nums[mid] == target)
                return true;
            
            if(nums[l] <= nums[mid]){ // left side array is increasing
                if(nums[l] <= target && target <= nums[mid]) r = mid - 1;
                else l = mid + 1;
            }else{ // left side array contains pivot
                if(nums[mid] < target && target <= nums[r]) l = mid + 1;
                else r = mid - 1;
            }
        }
        
        return false;
    }
};

int main(){
  return 0;
}