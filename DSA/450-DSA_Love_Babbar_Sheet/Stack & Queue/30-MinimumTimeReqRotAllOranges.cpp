// Question: https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=173f254cee8cacb0cca9a2ad775174db&pid=701754&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;

// APPROACH: Plain BFS + Queue
class Solution {
public:
    int xx[4] = { -1 , +1 , 0 , 0 };
    int yy[4] = { 0 , 0 , -1 , +1 };
    int n,m;
    
    bool valid(int i, int j){
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue<array<int,3>> q;
        n = grid.size();
        m = grid[0].size();
        
        int answerTime = 0;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==2) q.push({i,j,0});
        
        while(!q.empty()){
            auto k = q.front(); q.pop();
            answerTime = max(answerTime, k[2]);
            
            for(int i=0;i<4;i++){
                int newX = k[0] + xx[i];
                int newY = k[1] + yy[i];
                if(valid( newX , newY ) && grid[newX][newY]==1){
                    grid[newX][newY] = 2;
                    q.push({ newX , newY , k[2]+1 });
                }
            }
        }
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j] == 1) return -1;
                
        return answerTime;
    }
};

int main(){
	int tc; cin >> tc; while(tc--){
		int n, m; cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> grid[i][j];
		Solution obj;
		cout << obj.orangesRotting(grid) << "\n";
	}
	return 0;
}