// Question: https://codeforces.com/problemset/problem/455/A
// Solution: https://codeforces.com/contest/455/submission/82244203

#include <bits/stdc++.h>
#define ll long long
#define l long
#define sht short
#define pb push_back
#define mkpr make_pair
#define NL cout<<"\n";
#define optimize ios::sync_with_stdio(0);cin.tie(0);
#define PI 3.14159265358979323846
#define MAXN 100001
using namespace std;
int main(){
    optimize
    ////// Code here
    ll int n,x;
    ll int dp[MAXN]={0};
    ll int c[MAXN]={0};
    cin>>n;
    while(n--){
        cin>>x;
        c[x]++;
    }
    dp[0]=0;
    dp[1]=c[1];
    for(ll int i=2;i<MAXN;i++){
        dp[i]=max(dp[i-1],dp[i-2]+i*c[i]);
    }
    cout<<dp[MAXN-1];
    NL
}