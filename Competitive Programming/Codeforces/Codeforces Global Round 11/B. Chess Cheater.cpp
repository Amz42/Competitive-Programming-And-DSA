// Question: https://codeforces.com/contest/1427/problem/B
// Solution: https://codeforces.com/contest/1427/submission/95158031

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
        ll int n,k; cin>>n>>k;
        string s; cin>>s;
        ll int win_streaks=0, wins=0;
        vector<int> gaps;
        
        fori(n){
            if(s[i]=='L'){
                ll int count=0;
                while(i<n && s[i+1]=='L') count++, i++;
                gaps.pb(count+1);
            }else{
                ll int count=0;
                while(i<n && s[i+1]=='W') count++, i++;
                win_streaks += 1;
                wins += count+1;
            }
        }
        
        if(wins+k>=n){
            cout<<2*n-1; NL
            continue;
        }
        if(wins==0){
            cout<<max((ll int)0,2*k-1); NL
            continue;
        }
        
        if(s[0]=='L') gaps[0] = INT_MAX;
        if(s[n-1]=='L') gaps[gaps.size()-1] = INT_MAX;
        
        sort_a(gaps);
        
        ll int gaps_we_can_fill=0, sum = 0;
        for(auto h: gaps){
            if(h+sum>k) break;
            sum += h;
            gaps_we_can_fill++;
        }
        
        cout<<2*(k+wins)-win_streaks+gaps_we_can_fill;
        NL
    }
    
	return 0;
}