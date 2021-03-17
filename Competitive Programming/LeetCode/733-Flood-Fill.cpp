// Question: https://leetcode.com/problems/flood-fill/
// Solution: https://leetcode.com/submissions/detail/468936567/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n,m;
    bool valid(int i, int j){
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n = image.size();
        if(n==0 || image[sr][sc] == newColor) return image;
        m = image[0].size();
        
        int XY[4][2] = {
            {-1,0}, // UP
            {+1,0}, // DOWN
            {0,-1}, // LEFT
            {0,+1} // RIGHT
        };
        
        int srcColor = image[sr][sc];
        image[sr][sc] = newColor;
        
        queue<pair<int,int>> q; q.push({sr,sc});
        while(!q.empty()){
            auto k = q.front(); q.pop();
            int cx = k.first;
            int cy = k.second;
            
            for(int i=0;i<4;i++){
                int nx = cx + XY[i][0];
                int ny = cy + XY[i][1];
                
                if(valid(nx, ny) && image[nx][ny] == srcColor){
                    image[nx][ny] = newColor;
                    q.push({nx,ny});
                }
            }
        }
        
        return image;
    }
};