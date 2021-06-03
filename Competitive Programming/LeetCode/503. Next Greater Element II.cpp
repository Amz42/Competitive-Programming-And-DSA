// Question: https://leetcode.com/problems/next-greater-element-ii/
// Solution: https://leetcode.com/submissions/detail/499910446/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> s;
        
        for(int i = 2*n-1; i>=0; i--){
            while(!s.empty() && s.top() <= nums[i%n]) s.pop();
            
            ans[i%n] = s.empty() ? -1 : s.top();
            
            s.push(nums[i%n]);
        }
        
        return ans;
    }
};

int main(){
  return 0;
}