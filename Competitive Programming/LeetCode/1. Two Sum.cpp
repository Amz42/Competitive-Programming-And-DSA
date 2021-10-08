// Question: https://leetcode.com/problems/two-sum/
// Solution-1: https://leetcode.com/submissions/detail/414168787/
// Solution-2: https://leetcode.com/submissions/detail/566924696/

#include<bits/stdc++.h>
using namespace std;

class Solution1 {
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

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> answer;
        
        for(int i=0;i<nums.size();i++){
            int a = nums[i];
            int b = target - nums[i];
            
            if(mp[b] != 0){
                answer.push_back(mp[b]-1);
                answer.push_back(i);
                break;
            }
            
            mp[a] = i+1;
        }
        
        return answer;
    }
};

int main(){
  return 0;
}