// Question: https://codeforces.com/problemset/problem/118/E
// Solution: https://codeforces.com/contest/118/submission/84521851

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mkpr make_pair
#define NL cout<<"\n";
#define optimize ios::sync_with_stdio(0);cin.tie(0);
#define fori(n) for(ll int i=0;i<n;i++)
#define ten5 100000
using namespace std;
vector<ll int> adj[ten5+1];
set<pair<int,int>> ans;
bool visited[ten5+1]={0};
int in[ten5+1],low[ten5+1];
int bridges=0,timer;
void bridge(int node, int par){
    visited[node]=1;
    in[node] = low[node] = timer;
    timer++;
    for(int child: adj[node]){
        if(child == par) continue;
        if(visited[child]){
            low[node] = min(low[node], in[child]);
        }else{
            bridge(child, node);
            if(low[child] > in[node]) bridges++;
            low[node] = min(low[node], low[child]);
        }
    }
}
void dfs(int node,int par){
    visited[node] = 1;
    for(int child: adj[node]){
        if(!visited[child]){ans.insert(mkpr(node,child)),dfs(child,node);}
        else if(child != par && ans.find(mkpr(child,node))==ans.end()){ans.insert(mkpr(node,child));}
    }
}
int main(){
    optimize
    ll int n,m,a,b;
    cin>>n>>m;
    while(m--) cin>>a>>b, adj[a].pb(b), adj[b].pb(a);
    bridge(1,-1);
    if(bridges) cout<<0;
    else{
        fori(ten5+1) visited[i] = 0;
        dfs(1,-1);
        for(auto k: ans) cout<<k.first<<" "<<k.second<<"\n";
    }
	return 0;
}