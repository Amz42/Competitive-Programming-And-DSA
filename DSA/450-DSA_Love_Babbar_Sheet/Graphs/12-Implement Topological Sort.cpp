// Question: https://practice.geeksforgeeks.org/problems/topological-sort/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=d80d4e404cdb3fa63b6695b118ced533&pid=700255&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	vector<int> topoSort(int V, vector<int> adj[]) {
	    
	    int inDegree[V] = {0};
	    for(int node=0;node<V;node++)
	        for(auto k: adj[node])
	            inDegree[k]++;
	    
	    vector<int> answer;
	    queue<int> q;
	    
	    for(int node=0;node<V;node++)
	        if(inDegree[node] == 0)
	            q.push(node);
	    
	    while(!q.empty()){
	        int node = q.front(); q.pop();
	        answer.push_back(node);
	        
	        for(auto k: adj[node]){
	            if(--inDegree[k]==0)
	                q.push(k);
	        }
	    }
	    
	    return answer;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends