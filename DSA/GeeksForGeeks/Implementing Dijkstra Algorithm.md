### GeeksForGeeks - Implementing Dijkstra Algorithm

[Question](https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=ba6812503a0c9e63b7c9204aa7a0b9c2&pid=700334&user=amanguptarkg6)

#### C++
```c++
// Time Complexity: O((N+E)logN) N = no. of nodes, E = no. of edges
// Space Complexity: O(N) heap + O(N) distance array

class Solution{
public:
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int source){
        // min-heap
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;
        vector<int> dist(n, INT_MAX);
        
        dist[source] = 0;
        pq.push({0, source});
        
        while(!pq.empty()){
            int node_dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto k: adj[node]){
                if(node_dist + k[1] < dist[k[0]]){
                    dist[k[0]] = node_dist + k[1];
                    pq.push({dist[k[0]], k[0]});
                }
            }
        }
        
        return dist;
    }
};
```