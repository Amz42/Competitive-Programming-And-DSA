// Question: https://leetcode.com/problems/two-sum/
// Solution: https://leetcode.com/submissions/detail/414168787/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<long long int, vector<int>> mp;
        
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        
        vector<int> v;
        
        for(int i=0;i<n;i++){
            int a = nums[i];
            int b = target - a;
            if(a==b && mp[a].size()>1){
                v.push_back(mp[a][0]);
                v.push_back(mp[a][1]);
                break;
            }else if(a!=b && mp[b].size()){
                v.push_back(mp[a][0]);
                v.push_back(mp[b][0]);
                break;
            }
        }
        return v;
    }
};

int main(){
  return 0;
}