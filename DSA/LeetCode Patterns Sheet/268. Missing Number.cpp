// Question: https://leetcode.com/problems/missing-number/
// Solution: https://leetcode.com/submissions/detail/500527393/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xr = 0;
        for(int i=0;i<=nums.size();i++) xr ^= i;
        for(auto k: nums) xr ^= k;
        return xr;
    }
};

int main(){
  return 0;
}