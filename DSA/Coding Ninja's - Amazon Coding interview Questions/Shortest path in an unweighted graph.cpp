// Question: https://www.codingninjas.com/codestudio/problems/shortest-path-in-an-unweighted-graph_981297

#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int,int>> edges,int n ,int m,int s ,int t){
	vector<int> adj[n+1];
    vector<bool> vis(n+1, 0);
    
    for(auto k: edges)
        adj[k.first].push_back(k.second),
    	adj[k.second].push_back(k.first);
    
    int path[n+1] = {0};
    int lvl = 0;
    queue<int> q; q.push(s); vis[s] = true;
    while(!q.empty()){
        int node = q.front(); q.pop();
        if(node == t) break;
        for(auto k: adj[node]){
            if(!vis[k]){
                path[k] = node;
                vis[k] = true;
                q.push(k);
            }
        }
    }
    
    vector<int> answer;
    while(t!=s){
        answer.push_back(t);
        t = path[t];
    }
    answer.push_back(s);
    
    reverse(answer.begin(), answer.end());
    return answer;
}


int main(){
  return 0;
}