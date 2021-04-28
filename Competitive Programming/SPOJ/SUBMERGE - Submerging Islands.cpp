// Question: https://www.spoj.com/problems/SUBMERGE/
// Solution: https://www.spoj.com/submit/SUBMERGE/id=26313441

#include <bits/stdc++.h>
#define ll long long
#define u_map unordered_map
#define sht short
#define pb push_back
#define mkpr make_pair
#define NL cout<<"\n";
#define optimize ios::sync_with_stdio(0);cin.tie(0);
#define PI 3.14159265358979323846
#define fori(n) for(ll int i=0;i<(ll int)n;i++)
#define forj(n) for(ll int j=0;j<(ll int)n;j++)
#define MOD 1000000007 // 1e9+7
#define ten5 100000
#define ten6 1000000
#define ten9 1000000000
#define sort_a(v) sort(v.begin(),v.end());
#define sort_d(v) sort(v.begin(),v.end(),greater<ll int>());
#define maxv(v) *max_element(v.begin(),v.end()) // to find max element of a vector
#define LOWCASE(s) transform(s.begin(),s.end(),s.begin(),::tolower); // convert string to lowercase
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

int timer;
int in[10001],low[10001];
vector<int> adj[10001];
bool vis[10001];
set<int> cutvertex;

void dfs(int node, int par){
    vis[node] = 1;
    in[node]=low[node]=timer;
    timer++;
    int trees=0;
    for(auto k: adj[node]){
        if(k==par) continue;
        if(vis[k]){
            // back-edge to ancestor
            low[node] = min(low[node],in[k]);
        }else{
            // forward edge
            dfs(k,node);
            trees++;
            low[node] = min(low[node],low[k]);
            // testing for cutvertex
            if(in[node]<=low[k] && par!=-1) cutvertex.insert(node);
        }
    }
    if(node==1 && trees>1) cutvertex.insert(1);
}

int main(){
    optimize
    /////// Write from here
    int n,m,x,y;
    while(true){
        cin>>n>>m;
        if(n==0) break;
        
        cutvertex.clear();
        timer = 0;
        fori(n) adj[i+1].clear(), vis[i+1]=0;
        fori(m) cin>>x>>y, adj[x].pb(y), adj[y].pb(x);
        
        dfs(1,-1);
        cout<<cutvertex.size();
        NL
    }
    
    
	return 0;
}