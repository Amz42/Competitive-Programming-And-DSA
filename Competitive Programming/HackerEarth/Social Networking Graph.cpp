// Question: https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/social-networking-graph/
// Solution: https://www.hackerearth.com/submission/43399725/

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
 
vector<int> adj[ten6+1];
bool visited[ten6+1];
int dist[ten6+1]={0};
ll int lvl=0;
 
void bfs(int src,int e){
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    visited[src]=1;
    while(!q.empty()){
        int a = q.front();
        q.pop();
        if(dist[a] == e) lvl++;
        for(auto k: adj[a]){
            if(!visited[k]){
                visited[k] = true;
                dist[k] = dist[a] +1;
                q.push(k);
            }
        }
    }
}
 
int main(){
    optimize
    /////// Write from here
    
    ll int n,m,a,b,qs; cin>>n>>m;
    
    fori(m) cin>>a>>b, adj[a].pb(b), adj[b].pb(a);
    
    cin>>qs;
    fori(qs){
        // cleaning the arrays
        fori(n+1) visited[i]=0, dist[i]=0;
        
        cin>>a>>b;
        
        lvl=0;
        bfs(a,b);
        
        cout<<lvl;
        NL
    }
    
    return 0;
}