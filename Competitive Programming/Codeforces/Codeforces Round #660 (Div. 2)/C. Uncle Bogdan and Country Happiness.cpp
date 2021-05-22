// Question: https://codeforces.com/contest/1388/problem/C
// Solution: https://codeforces.com/contest/1388/submission/88539478

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fori(n) for(ll int i=0;i<(ll int)n;i++)
#define ten5 1'00'000
using namespace std;

bool yes;
vector<ll int> h,p,happy(ten5);
vector<int> adj[ten5+1];

int dfs(int node,int par){
    int people = p[node];
    int happyc = 0;
    for(auto k: adj[node]){
        if(k!=par){ 
            people += dfs(k,node);
            happyc += happy[k];
        }
    }
    
    happy[node] = (h[node]+people)/2;
    
    if( 
        (h[node]+people)%2 ||
        !(-people<=h[node] && h[node]<=people) ||
        happyc > happy[node]
    ) yes = false;
    return people;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    
    ll int tests; cin>>tests;
    while(tests--){
        ll int n,m; cin>>n>>m;
        int x,y;
        
        yes=true;
        fori(n) adj[i].clear(), happy[i]=0;
        h.clear();
        p.clear();
        
        fori(n) cin>>x, p.pb(x);
        fori(n) cin>>x, h.pb(x);
        // input adj list
        fori(n-1) cin>>x>>y, --x, --y, adj[x].pb(y), adj[y].pb(x);
        
        dfs(0,-1);
        
        if(yes) cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
    
	return 0;
}