// Question: https://practice.geeksforgeeks.org/problems/steps-by-knight/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=b8518c6178f75f48fa81e04dcc30761f&pid=701755&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
    public:
    int vis[1001][1001];
    bool isValid(int x, int y,int n){
        if (x < 1 || x > n || y < 1 || y > n || vis[x][y] == 1) return false;
        return true;
    }

    int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
        int srcX= KnightPos[0], srcY= KnightPos[1];
        int tX= TargetPos[0], tY= TargetPos[1];
        
        int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        
        int dist[N+1][N+1];
        memset(vis,0,sizeof(vis));
        memset(dist,0,sizeof(dist));
        
        queue<pair<int, int>> q; q.push({srcX, srcY});
        vis[srcX][srcY] = 1;
        dist[srcX][srcY] = 0;
        
        if (srcX == tX && srcY == tY) return dist[srcX][srcY];
        
        while (!q.empty()){
            int currX = q.front().first;
            int currY = q.front().second;
            q.pop();
            
            for (int i = 0; i < 8; i++){
                if (isValid(currX + dx[i], currY + dy[i],N)){
                    int newX = currX + dx[i];
                    int newY = currY + dy[i];
                    
                    dist[newX][newY] = dist[currX][currY] + 1;
                    vis[newX][newY] = 1;
                    q.push({newX, newY});
                    
                    if (newX == tX && newY == tY) return dist[newX][newY];
                }
            }
        }
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends