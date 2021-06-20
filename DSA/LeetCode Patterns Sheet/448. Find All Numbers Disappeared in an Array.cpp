// Question: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
// Solution: https://leetcode.com/submissions/detail/500532085/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            int e = nums[i]%n;
            if(e == 0) e = n;
            nums[e-1] += n;
        }
        
        vector<int> answer;
        
        for(int i=0;i<n;i++)
            if(nums[i]/n == 0 || nums[i]==n)
                answer.push_back(i+1);
        
        return answer;
    }
};

int main(){
  return 0;
}