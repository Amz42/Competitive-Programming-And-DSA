// Question: https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/
// Solution: https://leetcode.com/submissions/detail/500517224/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [&](vector<int>&a, vector<int>&b){
            return a[0] < b[0];
        });
        
        int answer = 0;
        int n = points.size();
        for(int i=0;i<n-1;i++)
            answer = max(answer, points[i+1][0]-points[i][0]);
        
        return answer;
    }
};

int main(){
  return 0;
}