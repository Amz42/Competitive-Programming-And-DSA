// Question: https://codeforces.com/contest/1433/problem/D
// Solution: https://codeforces.com/contest/1433/submission/96178518

/*                                              _                    _  _  ____
                                               / \   _ __ ___  ____ | || ||___ \
                                              / _ \ | '_ ` _ \|_  / | || |_ __) |
                                             / ___ \| | | | | |/ /  |__   _/ __/
                                            /_/   \_\_| |_| |_/___|    |_||_____|
*/
#include <bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define mkpr        make_pair
#define NL          cout<<"\n";
#define optimize    ios::sync_with_stdio(0);cin.tie(0);
#define fori(a,n)   for(ll int i=a;i<(ll int)n;i++)
#define forj(a,n)   for(ll int j=a;j<(ll int)n;j++)
#define all(v)      v.begin(),v.end()
#define maxv(v)     *max_element(all(v))
#define tests       ll int t;cin>>t;while(t--)
using namespace std;
int main(){
    optimize
    /////// Write from here
    
    tests{
        ll int n,x; cin>>n;
        // value, index
        vector<pair<ll int,ll int>> s;
        
        fori(0,n) cin>>x, s.pb(make_pair(x,i+1));
        
        sort(s.begin(),s.end());
        
        ll int index = 0;
        for(auto k: s){
            if(k.first != s[0].first) break;
            index++;
        }
        
        // all nodes with same value
        if(index==n){ cout<<"NO\n"; continue; }
        
        cout<<"YES\n";
        fori(index,n) cout<<s[0].second<<" "<<s[i].second<<endl;
        
        ll int i=1;
        while(s[i].first==s[0].first){ cout<<s[i].second<<" "<<s[index].second<<endl, i++; }
    }
    
	return 0;
}