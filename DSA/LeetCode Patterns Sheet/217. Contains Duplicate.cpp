// Question: https://leetcode.com/problems/contains-duplicate/
// Solution-1: https://leetcode.com/submissions/detail/500523084/
// Solution-2: https://leetcode.com/submissions/detail/500524100/

#include<bits/stdc++.h>
using namespace std;

class Solution1{
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(auto k: nums){
            if(s.find(k) != s.end())
                return true;
            s.insert(k);
        }
        
        return false;
    }
};

class Solution2 {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        for(int i=0;i<n-1;i++)
            if(nums[i]==nums[i+1])
                return true;
        
        return false;
    }
};

int main(){
  return 0;
}