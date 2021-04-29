// Question: https://codeforces.com/contest/427/problem/B
// Solution: https://codeforces.com/contest/427/submission/79904412

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll int prm(ll int num,ll int c){
    ll int x=num-c+1;
    return x<0?0:x;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll int n,t,c,count=0,ans=0,x; cin>>n>>t>>c;
    for(ll int i=0;i<n;i++){
        cin>>x;
        if(x>t){
            if(count!=0){ans+=prm(count,c);}
            count=0;
        }
        else count++;
    }
    if(count)ans+=prm(count,c);
    cout<<ans;
	return 0;
}