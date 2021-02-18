// Question: https://codeforces.com/contest/1440/problem/C1
// Solution: https://codeforces.com/contest/1440/submission/98758898

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
        int n,m; cin>>n>>m;
        bool a[n][m];
        char c;
        fori(0,n){
            forj(0,m){
                cin>>c, a[i][j] = c-'0';
            }
        }
        
        vector<pair<int,int>> answer;
        
        // handle starting n-2 rows
        for(int i=0;i<n-2;i++){
            if(i%2==0){ // --->
                for(int j=0;j<m-1;j++){
                    if(a[i][j]){ 
                        a[i][j] ^= 1, a[i][j+1] ^= 1, a[i+1][j+1] ^= 1;
                        answer.pb({i,j}), answer.pb({i,j+1}), answer.pb({i+1,j+1});
                    }
                }
                // last column
                if(a[i][m-1]){ 
                    a[i][m-1] ^= 1, a[i+1][m-1] ^= 1, a[i+1][m-2] ^= 1;
                    answer.pb({i,m-1}), answer.pb({i+1,m-1}), answer.pb({i+1,m-2});
                }
            }
            
            else{      // <---
                for(int j=m-1;j>0;j--){
                    if(a[i][j]){ 
                        a[i][j] ^= 1, a[i][j-1] ^= 1, a[i+1][j-1] ^= 1;
                        answer.pb({i,j}), answer.pb({i,j-1}), answer.pb({i+1,j-1});
                    }
                }
                // last column
                if(a[i][0]){ 
                    a[i][0] ^= 1, a[i+1][0] ^= 1, a[i+1][1] ^= 1;
                    answer.pb({i,0}), answer.pb({i+1,0}), answer.pb({i+1,1});
                }
            }
        }
        
        // handle last 2 rows
        for(int j=0;j<m-2;j++){
            if(a[n-2][j]){
               a[n-2][j] ^= 1, a[n-2][j+1] ^= 1, a[n-1][j+1] ^= 1;
               answer.pb({n-2,j}), answer.pb({n-2,j+1}), answer.pb({n-1,j+1});
            }
            
            if(a[n-1][j]){
               a[n-1][j] ^= 1, a[n-1][j+1] ^= 1, a[n-2][j+1] ^= 1;
               answer.pb({n-1,j}), answer.pb({n-1,j+1}), answer.pb({n-2,j+1});
            }
        }
        
        // handle last 2x2 grid
        queue<pair<int,int>> o,z;
        if(a[n-2][m-2]) o.push({n-2,m-2}); else z.push({n-2,m-2});
        if(a[n-2][m-1]) o.push({n-2,m-1}); else z.push({n-2,m-1});
        if(a[n-1][m-2]) o.push({n-1,m-2}); else z.push({n-1,m-2});
        if(a[n-1][m-1]) o.push({n-1,m-1}); else z.push({n-1,m-1});
        
        pair<int,int> p;
        
        if(o.size()==4){
            p = o.front(); o.pop(), z.push(p), answer.pb(p); a[p.first][p.second] = 0;
            p = o.front(); o.pop(), z.push(p), answer.pb(p); a[p.first][p.second] = 0;
            p = o.front(); o.pop(), z.push(p), answer.pb(p); a[p.first][p.second] = 0;
        }
        
        if(o.size()==1){
            p = o.front(); o.pop(), z.push(p), answer.pb(p); a[p.first][p.second] = 0;
            p = z.front(); z.pop(), o.push(p), answer.pb(p); a[p.first][p.second] = 1;
            p = z.front(); z.pop(), o.push(p), answer.pb(p); a[p.first][p.second] = 1;
        }
        
        if(o.size()==2){
            p = o.front(); o.pop(), z.push(p), answer.pb(p); a[p.first][p.second] = 0;
            p = z.front(); z.pop(), o.push(p), answer.pb(p); a[p.first][p.second] = 1;
            p = z.front(); z.pop(), o.push(p), answer.pb(p); a[p.first][p.second] = 1;
        }
        
        if(o.size()==3){
            p = o.front(); o.pop(), z.push(p), answer.pb(p); a[p.first][p.second] = 0;
            p = o.front(); o.pop(), z.push(p), answer.pb(p); a[p.first][p.second] = 0;
            p = o.front(); o.pop(), z.push(p), answer.pb(p); a[p.first][p.second] = 0;
        }
        
        cout<<answer.size()/3; NL
        for(int i=0;i<(int)answer.size();i+=3){
            cout<<answer[i].first+1<<" "<<answer[i].second+1<<" ";
            cout<<answer[i+1].first+1<<" "<<answer[i+1].second+1<<" ";
            cout<<answer[i+2].first+1<<" "<<answer[i+2].second+1<<" ";
            NL
        }
    }
    
	return 0;
}