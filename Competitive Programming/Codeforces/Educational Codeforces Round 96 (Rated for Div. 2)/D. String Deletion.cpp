// Question: https://codeforces.com/contest/1430/problem/D
// Solution: https://codeforces.com/contest/1430/submission/95295901

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
int main(){
    optimize
    /////// Write from here
    
    tests{
        ll int n, count=0; cin>>n;
        string s; cin>>s;
        
        vector<int> seg;
        char last = s[0];
        
        fori(s.size()){
            if(s[i]!=last){
                last = s[i];
                seg.pb(count);
                count=1;
            }else count++;
        }
        
        if(count) seg.pb(count);
        int killer=0, kills_available=0, ans=0;
        // counting available reducible segments
        for(auto k: seg) kills_available += k-1;// cout<<k<<" ";
        
        // NL
        
        // cout<<"kills_available: "<<kills_available; NL
        
        fori(seg.size()){
            if(kills_available<=0){
                ans += ceil(((float)(seg.size()-i))/2);
                break;
            }
            
            // if killer
            while(seg[killer]<=1) killer++;
            seg[killer]--, kills_available--;
            
            kills_available -= (seg[i]-1);
            seg[i]=0;
            
            ans++;
        }
        
        cout<<ans; NL
    }
    
	return 0;
}