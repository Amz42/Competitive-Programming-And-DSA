// Question: https://codeforces.com/contest/1393/problem/B
// Solution: https://codeforces.com/contest/1393/submission/89308107

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fori(n) for(ll int i=0;i<(ll int)n;i++)
#define forj(n) for(ll int j=0;j<(ll int)n;j++)
#define all(v) v.begin(),v.end()
#define sort_d(v) sort(all(v),greater<ll int>());
using namespace std;
map<ll int,ll int> mp;
set<int> f4,f2;
bool call(){
    vector<int> v;
    for(auto k: f2) v.pb(mp[k]);
    sort_d(v);
    int a = v[0];
    int b = v.size()>1 ? v[1] : 0;
    int c = v.size()>2 ? v[2] : 0;
    if(a>7 || (a>5 && b>1) || (b>1 && c>1)) return true;
    return false;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll int n,x,q; cin>>n;
    fori(n) cin>>x, mp[x]++;
    cin>>q; char c;
    for(auto k: mp){
        if(k.second>=4) f4.insert(k.first);
        if(k.second>=2) f2.insert(k.first);
    }
    forj(q){
        cin>>c>>x;
        if(c=='+'){
            mp[x]++, n++;
            if(mp[x]>=4) f4.insert(x);
            if(mp[x]>=2) f2.insert(x);
        }else{
            mp[x]--, n--;
            if(mp[x]<4) f4.erase(x);
            if(mp[x]<2) f2.erase(x);
        }
        if(n<8){cout<<"NO"<<endl; continue;}
        if(f4.size()!=0 && (f4.size()>1 || f2.size()>2 || call())) 
        cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
	return 0;
}