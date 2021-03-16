// Question: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=c800a6b3b811fa8a1e1f8c93cd89f925&pid=700219&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool vis[100001], cycle;
    
    void dfs(int node, vector<int>adj[], int parent){
        if(vis[node]){
            cycle = true;
            return;
        }
        vis[node] = true;
        
        for(auto k: adj[node]) if(k != parent) dfs(k, adj, node);
    }

	bool isCycle(int V, vector<int>adj[]){
	    memset(vis, false, sizeof(vis));
	    cycle = false;
	    
	    for(int i=0;i<V;i++){
	        if(!vis[i]) dfs(i, adj, -1);
	    }
	    
	    return cycle;
	}
};

// { Driver Code Starts.
int main(){
	int tc; cin >> tc; while(tc--){
		int V, E; cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v; cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends