// Question: https://leetcode.com/problems/search-in-rotated-sorted-array/
// Solution: https://leetcode.com/submissions/detail/428891437/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivot(vector<int> &v){
        int l=0, r = v.size()-1;
        int mid;
        while(l<r){
            mid = l + (r-l)/2;
            if(v[mid]>v[r]) l = mid+1;
            else            r = mid;
        }
        return l;
    }
    
    int bsearch(vector<int>& nums, int l, int r, int target){
        int mid = l + (r-l)/2;
        if(l>r) return -1;
        
        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) return bsearch(nums, mid+1, r, target);
        else return bsearch(nums, l, mid-1, target);
    }
    
    int search(vector<int>& nums, int target) {
        int pivt = pivot(nums);
        
        if(nums[pivt] == target) return pivt;
        
        int x = bsearch(nums, 0, pivt, target);
        int y = bsearch(nums, pivt, nums.size()-1, target);
        
        return max(x,y);
    }
};

int main(){
  return 0;
}