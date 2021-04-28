// Question: https://codeforces.com/contest/118/problem/D
// Solution: https://codeforces.com/contest/118/submission/83318157

#include <bits/stdc++.h>
#define ll long long
#define MOD8 100000000
using namespace std;
int fi,hi,kf,kh;
ll int dp[101][101][11][11];
bool visited[101][101][11][11]={0};
int solve(int f,int h,int k1,int k2){
    if(f+h==0)return 1;
    if(visited[f][h][k1][k2])return dp[f][h][k1][k2];
    ll int ans=0;
    if(f>0 && k1>0)ans+=solve(f-1, h, k1-1, kh);
    if(h>0 && k2>0)ans+=solve(f, h-1, kf, k2-1);
    visited[f][h][k1][k2]=true;
    dp[f][h][k1][k2]=ans%MOD8;
    return ans%MOD8;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>fi>>hi>>kf>>kh;
    cout<<solve(fi,hi,kf,kh)%MOD8;
	return 0;
}