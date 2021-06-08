// Question: https://leetcode.com/problems/single-number/
// Solution: https://leetcode.com/submissions/detail/500695683/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xr = 0;
        for(auto k: nums) xr ^= k;
        
        return xr;
    }
};

int main(){
  return 0;
}