// Question: https://leetcode.com/problems/trapping-rain-water/
// Solution: https://leetcode.com/submissions/detail/501291650/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int l = 0, r = n - 1;
        int maxRight = 0, maxLeft = 0;
        
        int answer = 0;
        while(l<r){
            maxLeft = max(maxLeft, h[l]);
            maxRight = max(maxRight, h[r]);
            
            if(maxRight > maxLeft)
                answer += (maxLeft - h[l++]);
            else
                answer += (maxRight - h[r--]);
        }
        
        return answer;
    }
};

int main(){
  return 0;
}