// Question: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=bea59de2dee90d5445a45d26dec4a215&pid=700218&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
    int vis[100001];
    bool cycle;
    
    void dfs(int node, vector<int> adj[]){
        if(vis[node] == 2) return; // already processed
        if(vis[node] == 1){ // already visited
            cycle = true;
            return;
        }
        vis[node] = 1; // mark as visited
        
        for(auto k: adj[node]) dfs(k, adj);
        vis[node] = 2; // mark as processed
    }

	bool isCyclic(int V, vector<int> adj[]) {
	   	memset(vis, 0, sizeof(vis));
	   	cycle = false;
	   	
	   	for(int i=0;i<V;i++){
	   	    // if this node is not processed yet
	   	    if(vis[i]==0) dfs(i, adj);
	   	}
	   	
	   	return cycle;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends