// Question: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=3b71a09938ada189addaac3595f6fe00&pid=700203&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<int> nodes;
    bool vis[100001];
    
    void dfs(int node, vector<int> adj[]){
        vis[node] = true;
        nodes.push_back(node);
        
        for(auto k: adj[node]) if(!vis[k]) dfs(k, adj);
    }

	vector<int>dfsOfGraph(int V, vector<int> adj[]){
	    nodes.clear();
	    memset(vis, false, sizeof(vis));
	    dfs(0, adj);
	    
	    return nodes;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends