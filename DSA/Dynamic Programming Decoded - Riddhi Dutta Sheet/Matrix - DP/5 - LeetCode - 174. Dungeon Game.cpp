// Question: https://leetcode.com/problems/dungeon-game/
// Solution: https://leetcode.com/submissions/detail/483039487/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
        int n = d.size();
        int m = d[0].size();
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1) {
                    d[i][j] = min(0, d[i][j]);
                } else if(i==n-1) { // last row
                    d[i][j] = min(0, d[i][j] + d[i][j+1]);
                } else if(j==m-1) { // last col
                    d[i][j] = min(0, d[i][j] + d[i+1][j]);
                } else {
                    d[i][j] = min(
                        0,
                        d[i][j] + max(d[i+1][j],d[i][j+1])
                    );
                }
            }
        }
        
        return abs(d[0][0])+1;
    }
};

int main(){
    Solution s = *new Solution();
    return 0;
}