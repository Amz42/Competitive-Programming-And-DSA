// Question: https://codeforces.com/contest/1437/problem/C
// Solution: https://codeforces.com/contest/1437/submission/96940905

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
ll int dp[200][301];
ll int a[200];

ll int fun_dp(int index, int num){
    if(index==n) return 0;
    if(num==3*n/2+1) return INT_MAX;
    if(dp[index][num]!=-1) return dp[index][num];
    dp[index][num] = min(fun_dp(index, num+1), fun_dp(index+1, num+1) + abs(a[index]-num));
    return dp[index][num];
}

int main(){
    optimize
    /////// Write from here
    
    tests{
        cin>>n;
        fori(0,n) cin>>a[i];
        sort(a, a+n);
        memset(dp, -1, sizeof(dp));
        cout<<fun_dp(0,1)<<endl;
    }
    
	return 0;
}