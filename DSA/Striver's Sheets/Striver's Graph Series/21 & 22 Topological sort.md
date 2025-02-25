## [Topological sort](https://www.geeksforgeeks.org/problems/topological-sort/1)

#### Solution-1: C++ | Using
```c++
class Solution {
    void dfs(
        int node,
        vector<vector<int>>& adj,
        stack<int>& stk,
        vector<bool>& visited
    ) {
        if (visited[node])
            return;
        
        visited[node] = true;
        for (int child: adj[node])
            dfs(child, adj, stk, visited);
        
        stk.push(node);
    }
public:
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n = adj.size();
        stack<int> stk;
        vector<bool> visited(n, false);
        
        vector<int> answer;
        for (int i=0;i<n;i++) {
            if(!visited[i]) {
                dfs(i, adj, stk, visited);
            }
        }
        
        while (!stk.empty()) {
            answer.push_back(stk.top());
            stk.pop();
        }
        
        return answer;
    }
};
```

#### Solution-2: C++ | Using Kahn's Algo - Topological Sorting with BFS
```c++
class Solution {
  public:
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> inDegree(n, 0);
        
        for (int i=0;i<adj.size();i++) {
            for (int child: adj[i]) {
                inDegree[child]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i<n; i++)
            if(inDegree[i] == 0)
                q.push(i);
            
        vector<int> answer;
        while(!q.empty()) {
            int node = q.front(); q.pop();
            answer.push_back(node);
            
            for (int child: adj[node]) {
                if (--inDegree[child] == 0)
                    q.push(child);
            }
        }
        
        return answer;
    }
};
```