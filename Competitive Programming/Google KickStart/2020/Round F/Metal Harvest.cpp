/*                                      _                    _  _  ____
                                       / \   _ __ ___  ____ | || ||___ \
                                      / _ \ | '_ ` _ \|_  / | || |_ __) |
                                     / ___ \| | | | | |/ /  |__   _/ __/
                                    /_/   \_\_| |_| |_/___|    |_||_____|
*/
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
/*struct hash_pair{
    template<class T1,class T2> 
    size_t operator()(const pair<T1,T2>& p)const{
        auto h1=hash<T1>{}(p.first);
        auto h2=hash<T2>{}(p.second); 
        return h1^h2;
    }
};*/
int main(){
    optimize
    /////// Write from here
    ll int g = 1;
    tests{
        ll int n,k,x,y; cin>>n>>k;
        vector<pair<ll int, ll int>> v;
        
        fori(n){cin>>x>>y;v.pb(mkpr(x,y));}
        sort(v.begin(),v.end());
        
        ll int avtill=0,robo=0;
        fori(n){
            x=v[i].first; y = v[i].second;
            if(avtill>=y) continue;
            if(avtill>x && avtill<y){x = avtill;}
            ll int diff = y-x;
            ll int f = (diff/k) + (diff%k ? 1:0);
            robo += f;
            avtill = x+f*k;
        }
        
        cout<<"Case #"<<g<<": "<<robo; NL
        g++;
    }
    
	return 0;
}