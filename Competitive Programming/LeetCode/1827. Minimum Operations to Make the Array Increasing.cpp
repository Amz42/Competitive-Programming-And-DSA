// Question: https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/
// Solution: https://leetcode.com/contest/biweekly-contest-50/submissions/detail/481740580/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int answer = 0;
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                answer += nums[i-1]+1 - nums[i];
                nums[i] = nums[i-1]+1;
            }
        }
        
        return answer;
    }
};

int main(){
    return 0;
}