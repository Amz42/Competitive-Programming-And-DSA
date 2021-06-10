// Question: https://leetcode.com/problems/minimum-size-subarray-sum/
// Solution: https://leetcode.com/submissions/detail/500849793/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& a) {
        int n = a.size();
        int l = 0, r = 0;
        int sum = 0;
        
        int answer = INT_MAX;
        while(r<n){
            sum += a[r];
            while(l<=r && sum-a[l]>=target) sum -= a[l++];
            
            if(sum>=target)
                answer = min(answer, r-l+1);
            r++;
        }
        
        return (answer == INT_MAX ? 0 : answer);
    }
};

int main(){
  return 0;
}