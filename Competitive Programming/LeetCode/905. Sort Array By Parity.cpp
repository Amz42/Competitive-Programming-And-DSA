// Question: https://leetcode.com/problems/sort-array-by-parity/
// Solution: https://leetcode.com/submissions/detail/495012378/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0)
                swap(nums[i], nums[l++]);
        }
        
        return nums;
    }
};

int main(){
    return 0;
}