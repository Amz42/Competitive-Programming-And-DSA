### Finding Bridges in a Graph

[CP-Algorithms Article Link](https://cp-algorithms.com/graph/bridge-searching.html)

##### C++
```c++
const int NODES = 1e5+1;
bool visited[NODES];
int in_time[NODES], low_time[NODES];
vector<int> adj[NODES];
int timer = 0;

void dfs(int node, int parent){
    visited[node] = true;
    low_time[node] = in_time[node] = timer++;

    for(int child: adj[node]){
        if(child == parent) continue;
        if(visited[child]){
            low_time[node] = min(low_time[node], in_time[child]);
        }else{
            dfs(child, node);
            if(in[node] < low_time[child])
                cout << "BRIDGE: " << node << " -> " << child << endl;
            low_time[node] = min(low_time[node], low_time[child]);
        }
    }
}
```

##### Related Question

[LeetCode 1192. Critical Connections in a Network](https://leetcode.com/problems/critical-connections-in-a-network/)
| [Solution](https://leetcode.com/submissions/detail/577083584/)