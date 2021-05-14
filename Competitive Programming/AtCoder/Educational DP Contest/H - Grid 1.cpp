// Question: https://atcoder.jp/contests/dp/tasks/dp_h
// Solution: https://atcoder.jp/contests/dp/submissions/17413755

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
#define MOD         1'000'000'007
#define ten5        1e5
#define all(v)      v.begin(),v.end()
#define sort_d(v)   sort(all(v),greater<ll int>());
#define maxv(v)     *max_element(all(v))
#define LOWCASE(s)  transform(all(s),s.begin(),::tolower);
#define UPCASE(s)   transform(all(s),s.begin(),::toupper);
#define setbits(b)  __builtin_popcount(b);
#define tests       ll int t;cin>>t;while(t--)
using namespace std;

ll int dp[1002][1002];
ll int mat[1002][1002];
int main(){
    optimize
    /////// Write from here
    
    ll int r,c; cin>>r>>c;
    char ch;
    
    fori(0,r){
        forj(0,c){ cin>>ch; if(ch=='.') mat[i][j]=1;}
    }
    dp[0][0] = 1;
    fori(0,r){
        forj(0,c){
            if(mat[i][j]==0) continue;
            // right
            if(mat[i][j+1]) dp[i][j+1] = (dp[i][j+1]+dp[i][j]) % MOD;
            // down
            if(mat[i+1][j]) dp[i+1][j] = (dp[i+1][j]+dp[i][j]) % MOD;
        }
    }
    
    // fori(0,r){
    //     forj(0,c){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     NL
    // }
    // NL NL
    
    
    cout<<dp[r-1][c-1];
    
	return 0;
}