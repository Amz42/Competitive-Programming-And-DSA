// Question: https://codeforces.com/contest/1447/problem/C
// Solution: https://codeforces.com/contest/1447/submission/98500713

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
int main(){
    optimize
    /////// Write from here
    
    tests{
        ll int n, w, x; cin>>n>>w;
        vector<pair<ll int, ll int>> v;
        
        fori(0,n){
            cin>>x;
            if(x<=w) v.pb(make_pair(x,i+1));
        }
        sort(v.begin(), v.end());
        
        if(w&1) w++;
        
        int g = v.size()-1;
        ll int sum = 0;
        vector<ll int> answer;
        while(g>=0 && sum<w/2){
            if(sum+v[g].first<=w){
                sum += v[g].first;
                answer.pb(v[g].second);
            }
            g--;
        }
        
        
        if(sum<w/2){
            cout<<"-1";
        }else{
            cout<<answer.size(); NL
            for(ll int k: answer) cout<<k<<" ";
        }
        NL
    }
    
	return 0;
}