# Bipartite Check (Undirected Graph)

## BFS
```c++
// Time Complexity: O(N+E) traversal
// Space Complexity: O(N+E) adj list + O(N) visited array + O(N) BFS queue

bool isBipartite_BFS_UDG(int i, vector<vector<int>>& adj, vector<int>& visited){
    queue<int> q; q.push(i);
    visited[i] = 1;
    
    while(!q.empty()){
        int node = q.front(); q.pop();
        
        for(auto k: adj[node]){
            if(visited[k] == 0)
                q.push(k),
                visited[k] = visited[node] == 1 ? 2 : 1;
            else if(visited[k] != 0 && visited[node] == visited[k])
                return false;
        }
    }
    
    return true;
}
```

## DFS
```c++
// Time Complexity: O(N+E) traversal
// Space Complexity: O(N+E) adj list + O(N) recursion stack + O(N) color array

bool isBipartite_DFS_UDG(int node, vector<vector<int>>& adj, vector<int>& color){
    if(color[node] == 0)
        color[node] = 1;
    
    for(auto k: adj[node]){
        if(color[k] == 0){
            color[k] = color[node] == 1 ? 2 : 1;
            if(!isBipartite_DFS_UDG(k, adj, color))
                return false;
        } else if(color[k] == color[node])
            return false;
    }
    
    return true;
}
```