// Question: https://codeforces.com/contest/1399/problem/D
// Solution: https://codeforces.com/contest/1399/submission/89081446

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fori(n) for(ll int i=0;i<(ll int)n;i++)
#define all(v) v.begin(),v.end()
#define maxv(v) *max_element(all(v))
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll int test; cin>>test;
    while(test--){
        ll int n; cin>>n;
        string s; cin>>s;
        set<int> s0,s1;
        vector<int>v;
        fori(n) s0.insert(i+1), s1.insert(i+1);
        for(auto k : s){
            if(k=='0'){
                int g = *s0.begin(); v.pb(g);
                s1.insert(g); s0.erase(g);
            }else{
                int g = *s1.begin(); v.pb(g);
                s0.insert(g); s1.erase(g);
            }
        }
        cout<<maxv(v)<<"\n";
        for(auto k: v) cout<<k<<" "; 
        cout<<"\n";
    }
	return 0;
}