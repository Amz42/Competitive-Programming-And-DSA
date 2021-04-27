// Question: https://www.spoj.com/problems/TOPOSORT/
// Solution: https://www.spoj.com/submit/TOPOSORT/id=26323557

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
#define MOD 1'000'000'007
#define ten5 1'00'000
#define all(v) v.begin(),v.end()
#define sort_a(v) sort(all(v));
#define sort_d(v) sort(all(v),greater<ll int>());
#define maxv(v) *max_element(all(v))
#define LOWCASE(s) transform(all(s),s.begin(),::tolower);
#define UPCASE(s) transform(all(s),s.begin(),::toupper);
#define setbits(b) __builtin_popcount(b);
#define tests ll int t;cin>>t;while(t--)
using namespace std;
struct hash_pair{
    template<class T1,class T2> 
    size_t operator()(const pair<T1,T2>& p)const{
        auto h1=hash<T1>{}(p.first);
        auto h2=hash<T2>{}(p.second); 
        return h1^h2;
    }
};

vector<int> adj[10001];
vector<int> in(10001,0),ans;

bool topo(int n){
    priority_queue<int> q;
    fori(n) if(in[i]==0) q.push(-(i));
    
    while(!q.empty()){
        int node = -1*q.top();
        ans.pb(node);
        q.pop();
        for(auto k: adj[node]){
            in[k]--;
            if(in[k]==0) q.push(-k);
        }
    }
    
    return (int)ans.size() == n;
}

int main(){
    optimize
    /////// Write from here
    
    ll int n,m; cin>>n>>m;
    int x,y;
    fori(m) cin>>x>>y, adj[x-1].pb(y-1), in[y-1]++;;
    if(topo(n)){for(auto k: ans) cout<<k+1<<" ";}
    else{cout<<"Sandro fails.";}
    
	return 0;
}