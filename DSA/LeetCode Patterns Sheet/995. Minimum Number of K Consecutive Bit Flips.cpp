// Question: https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/
// Solution: https://leetcode.com/submissions/detail/501356751/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int answer = 0;
        
        bool FB = 0; // flipBit
        for(int i = 0; i < n ; i++){
            if(FB == nums[i]){
                if(i+k > n) return -1;
                
                FB ^= 1;
                answer++;
                nums[i] = -1;
            }
            
            if(i-k+1>=0 && nums[i-k+1] == -1)
                FB ^= 1;
        }
        
        return answer;
    }
};

int main(){
  return 0;
}