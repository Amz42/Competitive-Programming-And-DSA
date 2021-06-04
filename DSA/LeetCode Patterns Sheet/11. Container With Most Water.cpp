// Question: https://leetcode.com/problems/container-with-most-water/
// Solution: https://leetcode.com/submissions/detail/500827146/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& h) {
        int l = 0, r = h.size()-1;
        
        int answer = 0;
        while(l<r){
            answer = max(answer, (r-l) * min(h[l], h[r]));
            if(h[l] <= h[r]) l++;
            else r--;
        }
        
        return answer;
    }
};

int main(){
  return 0;
}