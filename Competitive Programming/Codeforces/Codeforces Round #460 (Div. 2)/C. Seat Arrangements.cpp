// Question: https://codeforces.com/contest/919/problem/C
// Solution: https://codeforces.com/contest/919/submission/81670728

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll int n,m,k; cin>>n>>m>>k;
    int a[n+1][m+1];
    for(ll int i=0;i<=n;i++){
        string s; cin>>s;
        for(ll int j=0;j<=m;j++){
            if(i==n || j==m){a[i][j]=1;continue;}
            if(s[j]=='*') a[i][j]=1;
            else a[i][j]=0;
        }
    }
    ll int ans=0;
    for(ll int i=0;i<=n;i++){
        ll int count=0;
        for(ll int j=0;j<=m;j++){
            if(a[i][j]==1){
                if(count>=k) ans += count-k+1; 
                count=0;
            }else if(a[i][j]==0){count++;}
        }
    }
    if(k>1){
        for(ll int i=0;i<=m;i++){
            ll int count=0;
            for(ll int j=0;j<=n;j++){
                if(a[j][i]==1){
                    if(count>=k) ans += count-k+1;
                    count=0;
                }else if(a[j][i]==0){count++;}
            }
        }
    }
    cout<<ans;
	return 0;
}