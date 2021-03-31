// Question: https://leetcode.com/problems/jump-game-ii/
// Solution: https://leetcode.com/submissions/detail/474413197/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int current_reach = 0;
        int max_reach = 0;
        
        for(int i=0;i<nums.size()-1;i++){
            max_reach = max(max_reach, i+nums[i]);
            
            if(i == current_reach){
                jumps++;
                current_reach = max_reach;
            }
        }
        
        return jumps;
    }
};

int main(){
    return 0;
}