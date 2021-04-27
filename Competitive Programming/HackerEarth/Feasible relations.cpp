// Question: https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/feasible-relations/
// Solution: https://www.hackerearth.com/submission/56865539/

#include <bits/stdc++.h>
#define ll long long
#define sht short
#define pb push_back
#define mkpr make_pair
#define NL cout<<"\n";
#define optimize ios::sync_with_stdio(0);cin.tie(0);
#define fori(n) for(ll int i=0;i<n;i++)
#define ten6 1000000
using namespace std;
ll int cur_cc;
bool visited[ten6+1]={0};
int cc[ten6+1]={0};
vector<int> adj[ten6+1];
void dfs(int x){
    visited[x] = true; cc[x] = cur_cc;
    for(auto k: adj[x]){if(!visited[k]) dfs(k);}
}
int main(){
    optimize
    ll int t,n,k; cin>>t;
    while(t--){
        cin>>n>>k;
        int a,b;
        string s;
        vector<pair<int,int>> v;
        fori(n+1) adj[i].clear(), visited[i]=0, cc[i]=0;
        fori(k){
            cin>>a>>s>>b;
            if(s=="=") adj[a].pb(b), adj[b].pb(a);
            else v.pb(mkpr(a,b));
        }
        cur_cc = 1;
        for(int i=1;i<=n;i++){
            if(!visited[i]){dfs(i);cur_cc++;}
        }
        bool ans_yes = true;
        for(auto k: v){
            int x = k.first; int y = k.second;
            if(cc[x]==cc[y]){ans_yes = false; break;}
        }
        if(ans_yes) cout<<"YES";
        else cout<<"NO";
        NL
    }
	return 0;
}