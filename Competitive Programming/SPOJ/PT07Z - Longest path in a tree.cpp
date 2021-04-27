// Question: https://www.spoj.com/problems/PT07Z/
// Solution: https://www.spoj.com/submit/PT07Z/id=26169029

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
struct hash_pair{
    // used for u_map's key as pair
    template<class T1,class T2> 
    size_t operator()(const pair<T1,T2>& p)const{
        auto h1=hash<T1>{}(p.first);
        auto h2=hash<T2>{}(p.second); 
        return h1^h2;
    }
};

ll int n,maxd=-1,maxn;
vector<ll int> adj[10001];
bool visited[10001]={0};

void dfs(ll int x, ll int dist){
    visited[x] = true;
    if(dist>maxd) maxd=dist, maxn = x;
    
    for(auto k: adj[x]){
        if(!visited[k]) dfs(k,dist+1);
    }
}

int main(){
    optimize
    /////// Write from here
    
    cin>>n;
    ll int a,b;
    
    fori(n-1) cin>>a>>b , adj[a].pb(b), adj[b].pb(a);
    
    dfs(1,0);
    
    // clearing the visited array
    fori(10001) visited[i] = 0;
    
    maxd=-1;
    dfs(maxn,0);
    
    cout<<maxd;
    
	return 0;
}