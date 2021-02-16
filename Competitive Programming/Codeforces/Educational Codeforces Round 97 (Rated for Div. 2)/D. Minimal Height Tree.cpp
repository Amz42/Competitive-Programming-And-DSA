// Question: https://codeforces.com/contest/1437/problem/D
// Solution: https://codeforces.com/contest/1437/submission/96942444

/*                                              _                    _  _  ____
                                               / \   _ __ ___  ____ | || ||___ \
                                              / _ \ | '_ ` _ \|_  / | || |_ __) |
                                             / ___ \| | | | | |/ /  |__   _/ __/
                                            /_/   \_\_| |_| |_/___|    |_||_____|
*/
#include <bits/stdc++.h>
#define ll          long long
#define u_map       unordered_map
#define sht         short
#define pb          push_back
#define mkpr        make_pair
#define NL          cout<<"\n";
#define optimize    ios::sync_with_stdio(0);cin.tie(0);
#define fori(a,n)   for(ll int i=a;i<(ll int)n;i++)
#define forj(a,n)   for(ll int j=a;j<(ll int)n;j++)
#define MOD         1e9+7
#define ten5        1e5
#define all(v)      v.begin(),v.end()
#define sort_d(v)   sort(all(v),greater<ll int>());
#define maxv(v)     *max_element(all(v))
#define LOWCASE(s)  transform(all(s),s.begin(),::tolower);
#define UPCASE(s)   transform(all(s),s.begin(),::toupper);
#define setbits(b)  __builtin_popcount(b);
#define tests       ll int t;cin>>t;while(t--)
using namespace std;

ll int n;
vector<int> adj[2'00'001];
ll int deep[2'00'001];

ll int bfs(){
    queue<int> q; q.push(1); deep[1]=0;
    ll int depth = 0;
    
    while(!q.empty()){
        ll int par = q.front(); q.pop();
        depth = max(depth, deep[par]);
        for(auto k: adj[par]){
            deep[k] = deep[par]+1;
            q.push(k);
        }
    }
    
    return depth;
}

int main(){
    optimize
    /////// Write from here
    
    tests{
        ll int x; cin>>n;
        queue<ll int> a,q;
        
        fori(0,n) cin>>x, a.push(x);
        a.pop();
        
        fori(1,n+1) adj[i].clear();
        
        q.push(1);
        while(!q.empty()){
            ll int par = q.front(); q.pop();
            // cout<<par<<" ";
            ll int last = 0;
            while(!a.empty() && a.front()>last){
                ll int node = a.front(); a.pop();
                adj[par].pb(node);
                q.push(node);
                last = node;
            }
        }
        
        cout<<bfs()<<endl;
    }
    
	return 0;
}