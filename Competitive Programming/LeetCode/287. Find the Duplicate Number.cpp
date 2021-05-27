// Question: https://leetcode.com/problems/find-the-duplicate-number/
// Solution: https://leetcode.com/submissions/detail/445022625/

#include<bits/stdc++.h>
using namespace std;

/*
APPROACH: By Using Floyd's Cycle Detection Algo.
    1. Take 2 pointers fast & slow, fast will jump twice & slow will jump once in a move.
    2. Keep repeating above step until both pointers reach at same point.
    3. After they intersect, make both pointers slow & put 1 of them back at start position.
    4. Now simple make pointers jump once in each move.
    5. Keep repeating step 4 until them meet, that meeting point is the answer.
*/

class Solution{
public:
    int findDuplicate(vector<int>& nums) {
        int fast = nums[0];
        int slow = nums[0];
        
        do{
            fast = nums[nums[fast]];
            slow = nums[slow];
        }while(fast != slow);
        
        fast = nums[0];
        
        while(fast != slow){
            fast = nums[fast];
            slow = nums[slow];
        }
        
        return fast;
    }
};

int main(){
  return 0;
}