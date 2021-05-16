// Question: https://leetcode.com/problems/rotating-the-box/
// Solution: https://leetcode.com/submissions/detail/494064686/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        for(auto &v: box){
            int n = v.size();
            int i = n-1, j = n-1;
            
            while(i>=0){
                if(v[i]=='#'){ v[i] = '.'; v[j--] = '#';}
                if(v[i]=='*') j = i-1;
                i--;
            }
        }
        // return box;
        
        int n = box.size();
        int m = box[0].size();
        
        vector<vector<char>> ans(m, vector<char>(n));
        
        for(int i=0;i<m;i++){
            for(int j=n-1;j>=0;j--){
                ans[i][n-j-1] = box[j][i];
            }
        }
        
        return ans;
    }
};

int main(){
    return 0;
}