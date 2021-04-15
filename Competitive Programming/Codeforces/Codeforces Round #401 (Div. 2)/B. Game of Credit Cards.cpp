// Question: https://codeforces.com/contest/777/problem/B
// Solution: https://codeforces.com/contest/777/submission/95456142

/*                                      _                    _  _  ____
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
#define MOD         1'000'000'007
#define ten5        1'00'000
#define all(v)      v.begin(),v.end()
#define sort_a(v)   sort(all(v));
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
    
    int n; cin>>n;
    vector<char> a(n),b(n);
    fori(0,n) cin>>a[i];
    fori(0,n) cin>>b[i];
    sort_a(a); sort_a(b);
    int maxi = 0, mini = n, j1=0, j2=0;
    fori(0,n){
        if(b[i]>a[j1]) j1++, maxi++;
        if(b[i]>=a[j2]) j2++, mini--;
    }
    
    cout<<mini; NL
    cout<<maxi;
    
	return 0;
}