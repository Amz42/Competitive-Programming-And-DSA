// Question: https://www.codechef.com/problems/FIRESC
// Solution: https://www.codechef.com/viewsolution/34511180

#include <bits/stdc++.h>
#define ll long long
#define u_map unordered_map
#define sht short
#define pb push_back
#define mkpr make_pair
#define NL cout<<"\n";
#define optimize ios::sync_with_stdio(0);cin.tie(0);
#define PI 3.14159265358979323846
#define fori(n) for(ll int i=0;i<n;i++)
#define forj(n) for(ll int j=0;j<n;j++)
#define MOD 1000000007 // 1e9+7
#define ten5 100000
#define ten6 1000000
#define ten9 1000000000
#define maxv(v) *max_element(v.begin(),v.end()) // to find max element of a vector
using namespace std;

ll int ans;
bool visited[ten5+1]={0};
vector<ll int> adj[ten5+1];

ll int dfs(ll int x){
    // if(visited[x]) return 0;
    visited[x] = true;
    ll int nodes = 0;
    for(auto k: adj[x]){
        if(!visited[k]){
            nodes++;
            nodes += dfs(k);
        }
    }
    return nodes;
}

int main(){
    optimize
    /////// Write from here
    
    ll int t,n,m; cin>>t;
    while(t--){
        ll int a,b;
        ans = 1;
        cin>>n>>m;
        
        // clearing the visited & adj array
        fori(ten5+1){ 
            visited[i] = false;
            adj[i].clear();
        }
        
        fori(m){
            cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        
        ll int cc=0;
        for(ll int i=1;i<=n;i++){
            if(!visited[i]){
                cc++;
                ans *= (1 + dfs(i));
                ans %= MOD;
            }
        }
        
        cout<<cc<<" "<<ans%MOD;
        NL
    }
	return 0;
}