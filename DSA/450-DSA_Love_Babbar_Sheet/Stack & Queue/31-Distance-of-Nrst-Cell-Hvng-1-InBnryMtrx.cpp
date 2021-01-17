// Question: https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=4408282af3610eaa4e67795b80807c32&pid=701275&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

// APPROACH: Plain BFS & Queue
class Solution {
public:
    int xx[4] = { -1 , +1 , 0 , 0 };
    int yy[4] = { 0 , 0 , -1 , +1 };
    int n,m;
    bool valid(int i, int j){
        return ( (i<0 || i>=n || j<0 || j>=m) ? false : true);
    }

	vector<vector<int>>nearest(vector<vector<int>>grid){
	    n = grid.size();
	    m = grid[0].size();
	    
	    queue<array<int,2>> q;
	    vector<vector<int>> answer;
	    
	    for(int i=0;i<n;i++){
	        vector<int> v;
	        for(int j=0;j<m;j++){
	            v.push_back( ( grid[i][j] ?  0 : -1 ) );
	            if(grid[i][j]) q.push({ i , j });
	        }
	        answer.push_back(v);
	    }
	    
	    while(!q.empty()){
	        auto k = q.front(); q.pop();
	        for(int i=0;i<4;i++){
	            int newX = k[0] + xx[i];
	            int newY = k[1] + yy[i];
	            if(valid( newX , newY ) && !grid[newX][newY]){
	                grid[newX][newY] = 1;
	                q.push({ newX , newY });
	                answer[newX][newY] = answer[k[0]][k[1]] + 1;
	            }
	        }
	    }
	    
	    return answer;
	}
};

int main(){
	int tc; cin >> tc; while(tc--){
		int n, m; cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++) cin >> grid[i][j];
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i) cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}