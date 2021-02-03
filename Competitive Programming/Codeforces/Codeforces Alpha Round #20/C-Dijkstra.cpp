// Question: https://codeforces.com/problemset/problem/20/C
// Solution: https://codeforces.com/contest/20/submission/78661000

#include <bits/stdc++.h>
#define ll long long
#define INF 1000000000001
using namespace std;
int main(){
    ///////////////////////////////////////////////
    ////////       DIJKSTRA ALGORITHM      ////////
    ///////////////////////////////////////////////
    
    // for code optimization
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // n = no. of nodes
    // m = no. of edges
    ll int n,m; cin>>n>>m;
    
    ll int distance[n+1]; // stores the shortest distance of every node
    bool processed[n+1]={0}; // stores wheather a node is processed or not
    ll int parent[n+1]={0}; // keeps record of parent node of a node
    
    // stores adjacency list => {b,w}
    // its an array of vectors
    vector<pair<ll int,ll int>> adj[n+1];
    
    // storing adjacency list from user input
    for(ll int i=0;i<m;i++){
        ll int a,b,w; cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
        parent[b] = a;
    }
    
    priority_queue<pair<ll int,ll int>> q;
    
    // setting distance as infinite for all non-source nodes
    for(ll int i=1; i<=n;i++) distance[i] = INF;
    
    // picking up the first node
    distance[1] = 0;
    q.push({0,1});
    
    // finding shortest path for all nodes
    while (!q.empty()){
        ll int a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto u : adj[a]) {
            ll int b = u.first, w = u.second;
            if (distance[a]+w < distance[b]) {
                distance[b] = distance[a]+w;
                parent[b] = a;
                q.push({-distance[b],b});
            }
        }
    }
    
    
    // finding the path
    ll int x=n;
    vector<ll int>ans;
    while(true){
        if(x==1){ans.push_back(1); break;}
        if(x==0){cout<<-1; return 0;}
        ans.push_back(x);
        x=parent[x];
    }
    
    
    // printing the path
    for(ll int i=ans.size()-1;i>=0;i--){cout<<ans[i]<<" ";}
	return 0;
}