// Question: https://codeforces.com/contest/1425/problem/A
// Solution: https://codeforces.com/contest/1425/submission/96864819

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
        ll int n; cin>>n;
        ll int ans=0, i=0;
        while(n){
            ll int x;
            if( n%2==0 && (n%4!=0 || n==4) ) x = n/2;
            else x = 1;
            if(i%2==0) ans += x;
            i++;
            n -= x;
        }
        
        cout<<ans<<endl;
    }
    
	return 0;
}