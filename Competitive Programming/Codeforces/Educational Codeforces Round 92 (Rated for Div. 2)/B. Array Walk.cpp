// Question: https://codeforces.com/contest/1389/problem/B
// Solution: https://codeforces.com/contest/1389/submission/88394451

#include <bits/stdc++.h>
#define ll long long
#define fori(n) for(ll int i=0;i<(ll int)n;i++)
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    
    ll int test;
    cin>>test;
    while(test--){
        int n,k,z; cin>>n>>k>>z;
        vector<int> v(n),cf(n);
        
        // array input
        fori(n) cin>>v[i];
        cf[0] = v[0];
        // cumulative freq
        for(int i=1;i<n;i++) cf[i] = cf[i-1]+v[i];
        
        ll int ans = cf[k];
        for(int i=1;i<n;i++){
            // sum upto this point
            ll int sum = cf[i];
            // remaining moves
            int rem = k-i;
            if(rem<0) break;
            int zigzags = min(rem,2*z);
            sum += (zigzags/2)*(v[i-1]+v[i]) + (zigzags%2)*v[i-1];
            rem -= zigzags;
            sum += cf[i+rem] - cf[i];
            ans = max(ans,sum);
        }
        
        cout<<ans<<endl;
    }
    
	return 0;
}