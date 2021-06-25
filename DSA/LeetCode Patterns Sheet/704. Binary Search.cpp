// Question: https://leetcode.com/problems/binary-search/
// Solution: https://leetcode.com/submissions/detail/501897038/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        
        return -1;
    }
};

int main(){
  return 0;
}