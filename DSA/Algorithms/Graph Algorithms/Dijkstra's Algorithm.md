# Dijkstra's Algorithm

#### C++
```c++
// Time Complexity: O((N+E)logN) traversal + heap (insert / delete)
// Space Complexity: O(N) heap + O(N) distance

vector<int> Dijkstra(int source, vector<pair<int,int>> adj[]){
    // min-heap ; In pair => (dist,from)
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    // 1-indexed array for calculating shortest paths; 
	vector<int> dist(n+1,INT_MAX);
	
	dist[source] = 0;
	pq.push(make_pair(0,source));	// (dist,from)
	
	while( !pq.empty() ){
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
		
		vector<pair<int,int> >::iterator it;
		for( it = adj[prev].begin() ; it != adj[prev].end() ; it++){
			int next = it->first;
			int nextDist = it->second;
			if( dist[next] > dist[prev] + nextDist){
				dist[next] = dist[prev] + nextDist;
				pq.push(make_pair(dist[next], next));
			}
		}	
	}

    return dist;
}
```