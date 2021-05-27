// Question: https://leetcode.com/problems/largest-1-bordered-square/
// Solution: https://leetcode.com/submissions/detail/499109910/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        int up[101][101], left[101][101];
        
        // left calculation
        for(int i=0;i<n;i++){
            left[i][0] = a[i][0] ? 1 : 0;
            for(int j=1;j<m;j++){
                left[i][j] = a[i][j] ? left[i][j-1]+1 : 0;
            }
        }
        
        // up calculation
        for(int j=0;j<m;j++){
            up[0][j] = a[0][j] ? 1 : 0;
            for(int i=1;i<n;i++){
                up[i][j] = a[i][j] ? up[i-1][j]+1 : 0;
            }
        }
        
        int answer = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int d = min(up[i][j], left[i][j]);
                
                while(d > answer){
                    if(up[i][j-d+1] >= d && left[i-d+1][j] >= d)
                        answer = d;
                    d--;
                }
            }
        }
        
        return (answer*answer);
    }
};

int main(){
  return 0;
}