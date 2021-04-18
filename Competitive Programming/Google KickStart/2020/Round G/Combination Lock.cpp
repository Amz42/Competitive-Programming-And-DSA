/*                                              _                    _  _  ____
                                               / \   _ __ ___  ____ | || ||___ \
                                              / _ \ | '_ ` _ \|_  / | || |_ __) |
                                             / ___ \| | | | | |/ /  |__   _/ __/
                                            /_/   \_\_| |_| |_/___|    |_||_____|
*/
#include <bits/stdc++.h>
#define ll          long long
#define u_map       unordered_map
#define sht         short
#define pb          push_back
#define mkpr        make_pair
#define NL          cout<<"\n";
#define optimize    ios::sync_with_stdio(0);cin.tie(0);
#define PI          3.14159265358979323846
#define fori(a,n)   for(ll int i=a;i<(ll int)n;i++)
#define forj(a,n)   for(ll int j=a;j<(ll int)n;j++)
#define MOD         1e9+7
#define ten5        1e5
#define all(v)      v.begin(),v.end()
#define sort_d(v)   sort(all(v),greater<ll int>());
#define maxv(v)     *max_element(all(v))
#define LOWCASE(s)  transform(all(s),s.begin(),::tolower);
#define UPCASE(s)   transform(all(s),s.begin(),::toupper);
#define setbits(b)  __builtin_popcount(b);
#define tests       ll int t;cin>>t;while(t--)
using namespace std;

ll int fun(ll int x, ll int y, ll int n){
    if(x>y) swap(x,y);
    ll int a = y-x;
    ll int b = x+n-y;
    return min(a,b);
}

int main(){
    optimize
    /////// Write from here
    
    ll int g=1;
    tests{
        int w;
        ll int n,x; cin>>w>>n;
        vector<ll int> answer;
        ll int l[w];
        set<ll int> st;
        
        fori(0,w) cin>>x, l[i]=x, st.insert(x);
        
        for(auto k :st){
            ll int cost = 0;
            forj(0,w){ cost += fun(l[j],k,n);}
            answer.pb(cost);
        }
        
        
        cout<<"Case #"<<g<<": "<<*min_element(answer.begin(),answer.end()); NL
        g++;
    }
    
	return 0;
}




