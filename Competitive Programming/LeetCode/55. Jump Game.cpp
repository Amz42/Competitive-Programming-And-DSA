// Question: https://leetcode.com/problems/jump-game/
// Solution1: https://leetcode.com/submissions/detail/474397166/
// Solution2: https://leetcode.com/submissions/detail/474403737/

#include <bits/stdc++.h>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////        Solution 1
///////////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        if(nums[0]==0) return 0;
        int dist = 0;
        
        for(int i=n-2;i>=0;i--){
            dist++;
            if(nums[i]>=dist) dist = 0;
        }
        
        return (dist == 0);
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////        Solution 1
///////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////        Solution 2
///////////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int reach =0;
        
        for(int i=0;i<n;i++){
            if(reach <i) return false;
            
            reach=max(reach, i+nums[i]);
        }
        return true;
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////        Solution 2
///////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){
    return 0;
}