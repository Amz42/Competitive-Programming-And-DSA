// Question: https://leetcode.com/problems/longest-increasing-subsequence/
// DP O(n^2) Solution1: https://leetcode.com/submissions/detail/473019777/
// Optimized O(nlog(n)) Solution2: https://leetcode.com/submissions/detail/473021580/

#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////     Iterative DP O(n^2)
//////////////////////////////////////////////////////////////////////////////////////////////
class Solution1 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[2500] = {0};
        int answer = 0;
        
        for(int i=0;i<n;i++){
            int max_length_chain = 0;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i])
                    max_length_chain = max(max_length_chain, dp[j]);
            }
            
            dp[i] = max_length_chain + 1;
            answer = max(answer, dp[i]);
        }
        
        return answer;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////     Iterative DP O(n^2)
//////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////    Optimized O(nlog(n))
//////////////////////////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> v; v.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>v[v.size()-1]) v.push_back(nums[i]);
            else{
                auto k = lower_bound(v.begin(), v.end(), nums[i]);
                int index = k-v.begin();
                v[index] = nums[i];
            }
        }
        
        return v.size();
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////    Optimized O(nlog(n))
//////////////////////////////////////////////////////////////////////////////////////////////

int main(){
    return 0;
}