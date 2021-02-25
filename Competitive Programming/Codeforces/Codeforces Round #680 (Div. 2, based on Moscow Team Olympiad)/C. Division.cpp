// Question: https://codeforces.com/contest/1445/problem/C
// Solution: https://codeforces.com/contest/1445/submission/97379362

/*                                              _                    _  _  ____
                                               / \   _ __ ___  ____ | || ||___ \
                                              / _ \ | '_ ` _ \|_  / | || |_ __) |
                                             / ___ \| | | | | |/ /  |__   _/ __/
                                            /_/   \_\_| |_| |_/___|    |_||_____|
*/
#include <bits/stdc++.h>
#define ll          long long
#define optimize    ios::sync_with_stdio(0);cin.tie(0);
#define fori(a,n)   for(ll int i=a;i<(ll int)n;i++)
#define tests       ll int t;cin>>t;while(t--)
using namespace std;
int main(){
    optimize
    /////// Write from here
    
    tests{
        ll int p,q; cin>>p>>q;
        
        if(p%q){
            cout<<p<<"\n";
            continue;
        }
        
        set<ll int> factors; factors.insert(q);
        for(ll int i=2; i*i<=q; i++){
            if(q%i==0) factors.insert(i), factors.insert(q/i);
        }
        
        ll int answer = 0;
        for(auto k: factors){
            ll int ans = p;
            while(ans%q==0) ans/=k;
            answer = max(answer, ans);
        }
        
        cout<<answer<<"\n";
    }
    
	return 0;
}