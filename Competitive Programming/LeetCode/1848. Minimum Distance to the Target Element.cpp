// Question: https://leetcode.com/problems/minimum-distance-to-the-target-element/
// Solution: https://leetcode.com/contest/weekly-contest-239/submissions/detail/487668036/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int answer = 1e9;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target)
                answer = min(answer, abs(i-start));
        }
        
        return answer;
    }
};

int main(){
    return 0;
}