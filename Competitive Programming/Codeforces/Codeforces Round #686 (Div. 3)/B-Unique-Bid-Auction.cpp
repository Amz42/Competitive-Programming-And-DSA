// Question: https://codeforces.com/contest/1454/problem/B
// Solution: https://codeforces.com/contest/1454/submission/99527912

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
#define MOD         (int)(1e9+7)
#define ten5        (int)(1e5)
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
        int n; cin>>n;
        int freq[200002]={0};
        int a[n]; fori(0,n) cin>>a[i], freq[a[i]]++;
        
        ll int answer = INT_MAX;
        int pos = -1;
        for(int i=0;i<n;i++){
            if(freq[a[i]]==1){
                if(answer>a[i]){
                    answer = a[i];
                    pos = i+1;
                }
            }
        }
        
        cout<<pos;
        NL
    }
    
	return 0;
}