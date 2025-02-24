## [733. Flood Fill](https://leetcode.com/problems/flood-fill/)

#### Solution-1: C++ | Using BFS
```c++
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
```

#### Solution-2: C++ | Using DFS
```c++
class Solution {
    int direction[4][2] = {
        {0,1},
        {0,-1},
        {1,0},
        {-1,0}
    };
    void dfs(
        int x, int y,
        vector<vector<int>>& image,
        int &color,
        int initColor
    ){
        if (image[x][y] != initColor) return;
        image[x][y] = color;

        for (int i=0; i<4; i++) {
            int nodeX = x + direction[i][0];
            int nodeY = y + direction[i][1];
            if(
                0 <= nodeX && nodeX < image.size() &&
                0 <= nodeY && nodeY < image[0].size() &&
                image[nodeX][nodeY] == initColor
            )
                dfs(nodeX, nodeY, image, color, initColor);
        }
    }
public:
    vector<vector<int>> floodFill(
        vector<vector<int>>& image, int sr, int sc, int color
    ) {
        if (image[sr][sc] == color) {
            return image;
        }
        dfs(sr, sc, image, color, image[sr][sc]);
        return image;
    }
};
```