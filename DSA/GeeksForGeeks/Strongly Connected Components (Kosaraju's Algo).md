### GeeksForGeeks - Strongly Connected Components (Kosaraju's Algo)

[Question](https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=43460ad74cd9f7a0dd9bfdec3936ed76&pid=700394&user=amanguptarkg6)

#### C++
```c++
// Time Complexity: O(N+E) traversal
// Space Complexity: 2 * O(N+E) adj and trans_adj + O(N) visited and order stack

class Solution{
    void dfs1(int node, vector<int> adj[], bool visited[], stack<int>& order){
        visited[node] = true;
        
        for(auto k: adj[node])
            if(!visited[k])
                dfs1(k, adj, visited, order);
        
        order.push(node);
    }
    void dfs2(int node, vector<int> adj[], bool visited[]){
        visited[node] = true;
        
        for(auto k: adj[node])
            if(!visited[k])
                dfs2(k, adj, visited);
    }
public:
    int kosaraju(int n, vector<int> adj[]){
        vector<int> trans_adj[n];
        bool visited[n] = {0};
        stack<int> order;
        
        // creating adj transpose
        for(int i=0;i<n;i++)
            for(auto j: adj[i])
                trans_adj[j].push_back(i);
        
        for(int i=0;i<n;i++)
            if(!visited[i]) dfs1(i, adj, visited, order);
            
        for(int i=0;i<n;i++) visited[i] = false;
        
        int scc = 0;
        for(int i=0;i<n;i++){
            int node = order.top(); order.pop();
            if(!visited[node])
                scc++,
                dfs2(node, trans_adj, visited);
        }
        
        return scc;
    }
};
```