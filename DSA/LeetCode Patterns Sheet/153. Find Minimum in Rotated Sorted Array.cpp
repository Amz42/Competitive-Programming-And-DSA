// Question: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Solution: https://leetcode.com/submissions/detail/502753151/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        
        while(l<r){
            int mid = l + (r - l) / 2;
            if(nums[mid] < nums[r]) r = mid;
            else l = mid + 1;
        }
        
        return nums[l];
    }
};

int main(){
  return 0;
}