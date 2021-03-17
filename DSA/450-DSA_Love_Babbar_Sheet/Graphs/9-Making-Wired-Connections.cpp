// Question: https://leetcode.com/problems/number-of-operations-to-make-network-connected/
// Solution: https://leetcode.com/submissions/detail/468949716/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool vis[100001];
    void dfs(int node, vector<vector<int>>& adj){
        if(vis[node]) return;
        vis[node] = true;
        
        for(auto k: adj[node]) dfs(k, adj);
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        memset(vis, false, sizeof(vis));
        int e = connections.size();
        if(e < n-1) return -1; // (no. of edges) < (no. of nodes - 1)
        
        int components = 0;
        vector<vector<int>> adj(n);
        
        for(int i=0;i<e;i++)
            adj[connections[i][0]].push_back(connections[i][1]),
            adj[connections[i][1]].push_back(connections[i][0]);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){ dfs(i, adj); components++;}
        }
        
        return components-1;
    }
};