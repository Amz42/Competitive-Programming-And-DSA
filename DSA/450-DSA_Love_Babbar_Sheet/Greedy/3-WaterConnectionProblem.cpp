// Question: https://practice.geeksforgeeks.org/problems/water-connection-problem/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=4c2cefc3705bc9f2f6097a4ce0f0b27f&pid=3071&user=amanguptarkg6

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mkpr make_pair
#define NL cout<<"\n";
#define fori(n) for(ll int i=0;i<(ll int)n;i++)
#define forj(n) for(ll int j=0;j<(ll int)n;j++)
#define ten5 100000
#define ten6 1000000
#define ten9 1000000000
using namespace std;

int mini,leaf;
bool cycle = false;
vector<pair<int,int>> adj[21];
bool vis[21];

void dfs(int node){
    vis[node] = true;
    if(adj[node].size()==0) leaf = node;
    for(auto k: adj[node]){
        if(!vis[k.first]){
            mini = min(mini,(int)k.second);
            dfs(k.first);
        }else{
            cycle = true;
            return;
        }
    }
}

int main(){
    int tests = 0; cin>>tests;
    while(tests-->0){
        int n,m,x,y,d; cin>>n>>m;
        if(m==0){
            cout<<0;
            return 0;
        }
        
        for(int i=0;i<=n;i++) adj[i].clear(), vis[i]=0;
        
        set<int> receiver;
        fori(m) cin>>x>>y>>d, adj[x].pb(mkpr(y,d)), receiver.insert(y);
        
        map<pair<int,int>,ll int> mp;
        
        fori(n){
            if(receiver.find(i+1)==receiver.end() && !vis[i+1] && adj[i+1].size()){
                cycle = false;
                mini = ten9+1;
                dfs(i+1);
                if(cycle) continue;
                mp[mkpr(i+1,leaf)] = mini;
            }
        }
        
        cout<<mp.size()<<"\n";
        for(auto k: mp){
            x = k.first.first;
            y = k.first.second;
            d = k.second;
            cout << x << " " << y << " " << d << "\n";
        }
    }
    
	return 0;
}