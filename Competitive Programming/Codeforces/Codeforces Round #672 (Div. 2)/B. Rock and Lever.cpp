// Question: https://codeforces.com/contest/1420/problem/B
// Solution: https://codeforces.com/contest/1420/submission/96747424

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
struct hash_pair{
    template<class T1,class T2> 
    size_t operator()(const pair<T1,T2>& p)const{
        auto h1=hash<T1>{}(p.first);
        auto h2=hash<T2>{}(p.second); 
        return h1^h2;
    }
};
int main(){
    optimize
    /////// Write from here
    
    tests{
        ll int n,x; cin>>n;
        map<ll int,ll int> mp;
        
        fori(0,n){
            cin>>x;
            for(int j=63;j>=0;j--){
                if(x & (1<<j)){ mp[j]++; break; }
            }
        }
        
        ll int ans=0;
        fori(0,63){
            if(mp[i]){
                ans += (mp[i]*(mp[i]-1))/2;
            }
        }
        
        cout<<ans; NL
    }
    
	return 0;
}