// Question: https://codeforces.com/contest/1407/problem/B
// Solution: https://codeforces.com/contest/1407/submission/92460069

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
int main(){
    optimize
    /////// Write from here
    
    tests{
        int n; cin>>n;
        int a[n]; fori(n) cin>>a[i];
        sort(a, a+n);
        vector<int> ans;
        
        ans.pb(a[n-1]);
        int ggcd = a[n-1];
        a[n-1] = -1;
        
        
        fori(n-1){
            int tgcd = 1, index;
            forj(n){
                if(a[j]!=-1){
                    int h = __gcd(ggcd, a[j]);
                    if(h>=tgcd) tgcd=h, index = j;
                }
            }
            
            ggcd = tgcd;
            ans.pb(a[index]);
            a[index] = -1;
        }
        
        for(auto k: ans) cout<<k<<" ";
        NL
    }
    
	return 0;
}