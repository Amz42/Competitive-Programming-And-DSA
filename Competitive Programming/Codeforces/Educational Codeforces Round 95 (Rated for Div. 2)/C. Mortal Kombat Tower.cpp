// Question: https://codeforces.com/contest/1418/problem/C
// Solution: https://codeforces.com/contest/1418/submission/92957143

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

int n;
int arr[2*ten5+2];
int dp[2*ten5+2][2];

int fundp(int nn, bool frind){
    if(nn>=n) return 0;
    if(dp[nn][frind]!=INT_MAX) return dp[nn][frind];
    
    int cost = INT_MAX;
    
    cost = min(cost, fundp(nn+1,!frind) + (frind ? arr[nn] : 0) );
    if(nn<n-1) cost = min(cost, fundp(nn+2,!frind) + (frind ? arr[nn]+arr[nn+1] : 0) );
    
    dp[nn][frind] = cost;
    return cost;
}

int main(){
    optimize
    /////// Write from here
    
    tests{
        cin>>n;
        fori(n) dp[i][0]=dp[i][1]=INT_MAX;
        fori(n) cin>>arr[i];
        
        cout<<fundp(0,1);
        NL
    }
    
	return 0;
}