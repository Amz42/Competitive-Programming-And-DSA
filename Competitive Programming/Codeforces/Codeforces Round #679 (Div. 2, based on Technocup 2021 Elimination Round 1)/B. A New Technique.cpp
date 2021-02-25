// Question: https://codeforces.com/contest/1435/problem/B
// Solution: https://codeforces.com/contest/1435/submission/96676482

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
struct hash_pair{
    template<class T1,class T2> 
    size_t operator()(const pair<T1,T2>& p)const{
        auto h1=hash<T1>{}(p.first);
        auto h2=hash<T2>{}(p.second); 
        return h1^h2;
    }
};
int main(){
    optimize
    /////// Write from here
    
    tests{
        int n,m,x,k; cin>>n>>m;
        int answer[n][m];
        u_map<int,vector<int>> rows,cols;
        
        fori(0,n){
            cin>>x;
            rows[x].pb(x);
            forj(1,m){ cin>>k; rows[x].pb(k); }
        }
        
        fori(0,m){
            cin>>x;
            cols[x].pb(x);
            forj(1,n){ cin>>k; cols[x].pb(k); }
        }
        
        int e;
        bool f=false;
        for(auto k: rows){
            for(auto g: cols){
                if(k.first==g.first){
                    e = k.first; f =1;
                    break;
                }
            }
            if(f) break;
        }
        
        answer[0][0]=e;
        
        
        fori(0,m){
            int top = rows[e][i];
            forj(0,n){
                answer[j][i] = cols[top][j];
            }
        }
        
        
        fori(0,n){
            forj(0,m){
                cout<<answer[i][j]<<" ";
            }
            NL
        }
    }
    
	return 0;
}







 