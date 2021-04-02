// Question: https://codeforces.com/contest/1406/problem/C
// Solution: https://codeforces.com/contest/1406/submission/92924816

#include <bits/stdc++.h>
#define ll long long
#define u_map unordered_map
#define sht short
#define pb push_back
#define mkpr make_pair
#define NL cout<<"\n";
#define optimize ios::sync_with_stdio(0);cin.tie(0);
#define PI 3.14159265358979323846
#define fori(n) for(int i=0;i<(int)n;i++)
#define forj(n) for(int j=0;j<(int)n;j++)
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

int n;
vector<int> adj[ten5+1];
int siz[ten5+1];
vector<int> centroid;


void dfs(int node, int par=-1){
    siz[node] = 1;
    bool cntroid = true;
    
    for(auto k: adj[node]){
        if(k!=par){
            dfs(k,node);
            siz[node] += siz[k];
            if(siz[k]>n/2) cntroid = false;
        }
    }
    
    if(n-siz[node]>n/2) cntroid=false;
    
    if(cntroid) centroid.pb(node);
}


int main(){
    optimize
    /////// Write from here
    
    tests{
        cin>>n;
        
        // clearing adj list & visited array
        fori(n) adj[i+1].clear(), siz[i+1]=1;
        centroid.clear();
        
        int x,y;
        fori(n-1){ cin>>x>>y; adj[x].pb(y), adj[y].pb(x); }
        
        dfs(1,-1);
        
        if(centroid.size()==1){
            cout<<"1 "<<adj[1][0]; NL
            cout<<"1 "<<adj[1][0]; NL
        }else{
            x = centroid[0];
            y = centroid[1];
            for(auto k: adj[y]){
                if(k!=x){
                    cout<<y<<" "<<k; NL
                    cout<<x<<" "<<k; NL
                    break;
                }
            }
        }
    }
    
	return 0;
}