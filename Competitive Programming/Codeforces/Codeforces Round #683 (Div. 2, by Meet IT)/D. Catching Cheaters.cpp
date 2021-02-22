// Question: https://codeforces.com/contest/1447/problem/D
// Solution: https://codeforces.com/contest/1447/submission/98582350

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
int main(){
    optimize
    /////// Write from here
    
    int n, m, answer=0; cin>>n>>m;
    int dp[n+1][m+1]; memset(dp, 0, sizeof(dp));
    string a,b; cin>>a>>b;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 2);
            }else{
                dp[i][j] = max({
                    dp[i-1][j] - 1,
                    dp[i][j-1] - 1,
                    dp[i][j]
                });
            }
            answer = max(answer, dp[i][j]);
        }
    }
    
    cout<<answer;
	return 0;
}