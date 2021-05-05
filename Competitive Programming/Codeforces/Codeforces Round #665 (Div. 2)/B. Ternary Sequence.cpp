// Question: https://codeforces.com/contest/1401/problem/B
// Solution: https://codeforces.com/contest/1401/submission/90903028

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll int t; cin>>t;
    while(t--){
        ll int x,y,z,a,b,c; cin>>x>>y>>z>>a>>b>>c;
        ll int ans = 0,k=min(z,b);
        ans = k*2;
        z-=k; b-=k;
        c-=min(c,z);
        c-=min(c,x);
        ans -= c*2;
        cout<<ans<<endl;
    }
	return 0;
}