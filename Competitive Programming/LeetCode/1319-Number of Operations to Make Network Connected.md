## [1319. Number of Operations to Make Network Connected](https://leetcode.com/problems/number-of-operations-to-make-network-connected/)

#### Solution-1: C++ | Using DFS
```c++
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
```

#### Solution-2: Java | Using DFS
```java
class Solution {
    private int backEdges;
    private void dfs(
        int node, int parent,
        List<List<Integer>> graph,
        boolean[] visited
    ) {
        visited[node] = true;

        for (int neighbour: graph.get(node)) {
            if (neighbour == parent) continue;
            else if (visited[neighbour]) {
                backEdges++;
            } else {
                dfs(neighbour, node, graph, visited);
            }
        }
    }

    public int makeConnected(int n, int[][] connections) {
        backEdges = 0;
        boolean[] visited = new boolean[n];
        List<List<Integer>> graph = new ArrayList();
        for (int i=0; i<n; i++) {
            visited[i] = false;
            graph.add(new ArrayList());
        }

        for (int i=0; i<connections.length; i++) {
            int x = connections[i][0];
            int y = connections[i][1];
            graph.get(x).add(y);
            graph.get(y).add(x);
        }

        int totalConnectedComponents = 0;
        for (int i=0; i<n; i++) {
            if(!visited[i]) {
                totalConnectedComponents++;
                dfs(i, -1, graph, visited);
            }
        }
        
        // backEdges are counted twice, once from each node of the edge
        backEdges /= 2;

        int minEdgesRequired = totalConnectedComponents - 1;
        if (backEdges < minEdgesRequired)
            return -1;
        return minEdgesRequired;
    }
}
```