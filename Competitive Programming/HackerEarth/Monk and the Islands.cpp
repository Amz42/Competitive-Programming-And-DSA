// Question: https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/
// Solution: https://www.hackerearth.com/submission/43392258/

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
 
vector<int> adj[10001];
bool visited[10001]={0};
int dist[10001]={0};
 
void bfs(ll int src,ll int d){
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        //dist[curr] = d++;
        for(auto k: adj[curr]){
            if(!visited[k]) q.push(k), visited[k] = true , dist[k] = dist[curr]+1;
        }
        //d++;
    }
}
 
int main(){
    optimize
    /////// Write from here
    
    sht int t; cin>>t;
    while(t--){
        ll int n,m,x,y;
        cin>>n>>m;
        
        fori(10001) adj[i].clear(), visited[i]=0, dist[i]=0;
        
        // adj input
        fori(m) cin>>x>>y , adj[x].pb(y), adj[y].pb(x);
        // bfs calling
        bfs(1,0);
        
        cout<<dist[n];
        NL
    }
    
	return 0;
}