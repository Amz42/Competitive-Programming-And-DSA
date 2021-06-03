// Question: https://leetcode.com/problems/next-greater-element-i/
// Solution: https://leetcode.com/submissions/detail/499892693/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int mp[(int)(1e4+1)] = {0};
        stack<int> s;
        int n = nums2.size();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top()<nums2[i]) s.pop();
            mp[nums2[i]] = (s.empty() || s.top()<nums2[i] ? -1 : s.top());
            
            s.push(nums2[i]);
        }
        
        vector<int> ans;
        for(auto k: nums1) ans.push_back(mp[k]);
        
        return ans;
    }
};

int main(){
  return 0;
}