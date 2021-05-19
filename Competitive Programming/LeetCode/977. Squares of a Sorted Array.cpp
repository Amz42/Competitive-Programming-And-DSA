// Question: https://leetcode.com/problems/squares-of-a-sorted-array/
// Solution: https://leetcode.com/submissions/detail/495020974/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        int l = 0;
        int r = nums.size()-1;
        vector<int> answer(nums.size());
        
        int i = nums.size()-1;
        while(l<=r){
            if(abs(nums[l]) > abs(nums[r])){
                answer[i] = nums[l]*nums[l];
                l++;
            }else{
                answer[i] = nums[r]*nums[r];
                r--;
            }
            i--;
        }
        
        return answer;
    }
};

int main(){
  return 0;
}