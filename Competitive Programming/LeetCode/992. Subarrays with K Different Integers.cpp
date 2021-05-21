// Question: https://leetcode.com/problems/subarrays-with-k-different-integers/
// Solution: https://leetcode.com/submissions/detail/496176025/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int fun(vector<int>& nums, int k){
        int unique = 0;
        int freq[20001] = {0};
        
        int l = 0, answer = 0;
        for(int r = 0; r < nums.size(); r++){
            freq[nums[r]]++;
            if(freq[nums[r]] == 1)
                unique++;
            
            while(unique > k){
                freq[nums[l]]--;
                if(freq[nums[l]] == 0)
                    unique--;
                l++;
            }
            
            answer += (r - l + 1);
        }
        
        return answer;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fun(nums, k) - fun(nums, k-1);
    }
};

int main(){
  return 0;
}