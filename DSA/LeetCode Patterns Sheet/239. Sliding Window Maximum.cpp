// Question: https://leetcode.com/problems/sliding-window-maximum/
// Solution: https://leetcode.com/submissions/detail/474763652/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        for(int i=0;i<k-1;i++){
            while(q.size() && nums[q.back()]<nums[i]) q.pop_back();
            q.push_back(i);
        }
        
        vector<int> answer;
        for(int i=k-1;i<n;i++){
            while(q.size() && nums[q.back()]<nums[i]) q.pop_back();
            q.push_back(i);
            while(q.front() < i-k+1) q.pop_front();
            answer.push_back(nums[q.front()]);
        }
        
        return answer;
    }
};

int main(){
  return 0;
}