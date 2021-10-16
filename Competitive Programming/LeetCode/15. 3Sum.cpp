// Question: https://leetcode.com/problems/3sum/
// Solution: https://leetcode.com/submissions/detail/500781302/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int last = INT_MIN, n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> answer;
        for(int i=0;i<n;i++){
            if(nums[i]!=last){
                int l = i+1;
                int r = n-1;
                
                while(l<r){
                    int sum = nums[i] + nums[l] + nums[r];
                    if(sum==0){
                        vector<int> v = { nums[i], nums[l], nums[r] };
                        answer.push_back(v);
                        int ll = nums[l];
                        int rr = nums[r];
                        while(l<r && ll == nums[l] && rr == nums[r]) l++, r--;
                    }else if(sum>0) r--;
                    else l++;
                }
            }
            last = nums[i];
        }
        
        
        return answer;
    }
};

int main(){
  return 0;
}