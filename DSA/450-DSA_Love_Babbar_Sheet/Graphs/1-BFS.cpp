// Question: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=ec4842fc1e34f61be5e6d8e79fb525ae&pid=700217&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

vector <int> bfs(vector<int> g[], int N);

int main() {
    int T; cin >> T; while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector <int> res = bfs(adj, N);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout << endl;
    }
}

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/
vector <int> bfs(vector<int> g[], int N) {
    vector<int> answer;
    
    bool vis[N+1]={0}; vis[0] = 1;
    queue<int> q; q.push(0);
    
    while(!q.empty()){
        int node = q.front();
        answer.push_back(node); q.pop();
        
        for(auto k: g[node]){
            if(!vis[k]) q.push(k), vis[k] = 1;
        }
    }
    
    return answer;
}