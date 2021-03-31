// Question: https://leetcode.com/problems/sliding-window-maximum/
// O(N) Solution1: https://leetcode.com/submissions/detail/474763585/
// O(Nlog(N)) Solution2: https://leetcode.com/submissions/detail/474757864/

#include <bits/stdc++.h>
using namespace std;

//////////////////////// Solution 1 | O(N)
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

//////////////////////// Solution 2 | O(Nlog(N))
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int, greater<int>> s;
        for(int i=0;i<k-1;i++) s.insert(nums[i]);
        
        vector<int> answer;
        for(int i=0;i<=n-k;i++){
            s.insert(nums[i+k-1]);
            answer.push_back(*s.begin());
            s.erase(s.lower_bound(nums[i]));
        }
        
        return answer;
    }
};

int main(){
    return 0;
}