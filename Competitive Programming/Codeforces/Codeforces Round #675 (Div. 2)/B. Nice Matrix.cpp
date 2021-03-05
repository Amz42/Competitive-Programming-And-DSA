// Question: https://codeforces.com/contest/1422/problem/B
// Solution: https://codeforces.com/contest/1422/submission/94703251

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
        ll int n,m; cin>>n>>m;
        ll int a[n][m];
        fori(n){forj(m) cin>>a[i][j];}
        ll int ans = 0;
        
        for(int i=0;i<n/2;i++){
            for(int j=0;j<m/2;j++){
                ll int p = a[i][j];
                ll int q = a[i][m-j-1];
                ll int r = a[n-i-1][j];
                ll int s = a[n-i-1][m-j-1];
                
                ll int a1 = abs(q-p)+abs(r-p)+abs(s-p);
                ll int a2 = abs(p-q)+abs(r-q)+abs(s-q);
                ll int a3 = abs(p-r)+abs(q-r)+abs(s-r);
                ll int a4 = abs(p-s)+abs(q-s)+abs(r-s);
                
                ans += min(a1,min(a2,min(a3,a4)));
            }
        }
        
        // for mid column
        if(m%2){
            fori(n/2){
                ll int avg = (a[i][m/2]+a[n-i-1][m/2])/2;
                ans += abs(avg-a[i][m/2])+abs(avg-a[n-i-1][m/2]);
            }
        }
        // for mid row
        if(n%2){
            fori(m/2){
                ll int avg = (a[n/2][i]+a[n/2][m-i-1])/2;
                ans += abs(avg-a[n/2][i])+abs(avg-a[n/2][m-i-1]);
            }
        }
        
        cout<<ans;
        NL
    }
    
	return 0;
}