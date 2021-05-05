// Question: https://codeforces.com/contest/1401/problem/A
// Solution: https://codeforces.com/contest/1401/submission/90900842

#include <bits/stdc++.h>
#define ll long long
#define optimize ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main(){
    optimize
    ll int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        if(n-k<0) cout<<abs(n-k);
        else if((n-k)&1) cout<<1;
        else cout<<0;
        cout<<"\n";
    }
	return 0;
}