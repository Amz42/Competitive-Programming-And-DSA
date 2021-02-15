// Question: https://codeforces.com/contest/1452/problem/B
// Solution: https://codeforces.com/contest/1452/submission/99009512

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
        ll int n; cin>>n;
        ll int arr[n], mxxx=-1;
        for(int i=0;i<n;i++) cin>>arr[i], mxxx=max(mxxx,arr[i]);
        ll int remainde=0;
        
        for(int i=0;i<n;i++) remainde +=mxxx-arr[i];
        
        if(remainde>mxxx){ cout<<remainde-mxxx; NL;}
        
        else{
            ll int sum = accumulate(arr, arr+n, 0LL);
            ll int answer = 0;
            while(sum%(n-1)) answer++, sum++;
            cout<<answer; NL
        }
    }
    
	return 0;
}