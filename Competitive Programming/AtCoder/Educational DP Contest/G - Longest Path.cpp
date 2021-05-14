// Question: https://atcoder.jp/contests/dp/tasks/dp_g
// Solution: https://atcoder.jp/contests/dp/submissions/17412254

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
#define PI          3.14159265358979323846
#define fori(a,n)   for(ll int i=a;i<(ll int)n;i++)
#define forj(a,n)   for(ll int j=a;j<(ll int)n;j++)
#define MOD         1e9+7
#define ten5        1'00'005
#define all(v)      v.begin(),v.end()
#define sort_d(v)   sort(all(v),greater<ll int>());
#define maxv(v)     *max_element(all(v))
#define LOWCASE(s)  transform(all(s),s.begin(),::tolower);
#define UPCASE(s)   transform(all(s),s.begin(),::toupper);
#define setbits(b)  __builtin_popcount(b);
#define tests       ll int t;cin>>t;while(t--)
using namespace std;

ll int n,m,answer=0;
ll int in[ten5+1];
ll int dp[ten5+1];
vector<int> adj[ten5+1];

void topo(){
    queue<int> q;
    fori(0,n) if(in[i+1]==0){ q.push(i+1);}
    
    while(!q.empty()){
        int node = q.front(); q.pop();
        answer = max(answer, dp[node]);
        
        for(auto k: adj[node]){
            dp[k] = max(dp[k],dp[node]+1);
            in[k]--;
            
            if(in[k]==0) q.push(k);
        }
    }
}

int main(){
    optimize
    /////// Write from here
    
    cin>>n>>m;
    
    int x,y;
    fori(0,m){
        cin>>x>>y, in[y]++, adj[x].pb(y);
    }
    
    topo();
    
    cout<<answer;
    
	return 0;
}