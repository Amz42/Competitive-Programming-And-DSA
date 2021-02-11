// Question: https://codeforces.com/contest/1454/problem/E
// Solution: https://codeforces.com/contest/1454/submission/99574063

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
#define MOD         (int)(1e9+7)
#define ten5        (int)(1e5)
#define all(v)      v.begin(),v.end()
#define sort_d(v)   sort(all(v),greater<ll int>());
#define maxv(v)     *max_element(all(v))
#define LOWCASE(s)  transform(all(s),s.begin(),::tolower);
#define UPCASE(s)   transform(all(s),s.begin(),::toupper);
#define setbits(b)  __builtin_popcount(b);
#define tests       ll int t;cin>>t;while(t--)
using namespace std;
int main(){
    optimize
    /////// Write from here
    
    tests{
        int n, x, y; cin>>n;    // n = no. of nodes
        set<int> adj[n];
        vector<int> value(n,1);
        queue<int> leafs;
        
        // input adj list
        fori(0,n) cin>>x>>y, --x, --y, adj[x].insert(y), adj[y].insert(x);
        
        // pushing leaf nodes in queue
        fori(0,n) if(adj[i].size() == 1) leafs.push(i);
        
        while(!leafs.empty()){
            int node = leafs.front(); leafs.pop();
            int parent = *adj[node].begin();
            
            value[parent] += value[node];
            value[node] = 0;
            
            adj[node].clear();
            adj[parent].erase(node);
            
            if(adj[parent].size()==1){ // if parent node is leaf node now
                leafs.push(parent);
            }
        }
        
        ll int answer = 0;
        
        fori(0,n){
            answer += (1LL * value[i] * (value[i]-1) / 2);  // for tree
            answer += (1LL * value[i] * (n - value[i]));    // for cycle
        }
        
        cout<<answer;
        NL
    }
    
	return 0;
}