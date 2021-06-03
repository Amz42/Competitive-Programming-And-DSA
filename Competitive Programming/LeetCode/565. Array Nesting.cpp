// Question: https://leetcode.com/problems/array-nesting/
// Solution: https://leetcode.com/submissions/detail/500391812/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int answer = 0;
        
        for(int i = 0; i<n; i++){
            int p = i;
            int count = 0;
            
            while(p>=0 && nums[p]>=0){
                int x = p;
                p = nums[p];
                nums[x] = -1;
                count++;
            }
            
            answer = max(answer, count);
        }
        
        return answer;
    }
};

int main(){
  return 0;
}