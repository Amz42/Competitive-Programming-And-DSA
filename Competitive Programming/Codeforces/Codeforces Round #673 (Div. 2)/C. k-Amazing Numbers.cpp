// Question: https://codeforces.com/contest/1417/problem/C
// Solution: https://codeforces.com/contest/1417/submission/95996431

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
        ll int n,x; cin>>n;
        // to store position of elements in a map
        map<ll int, vector<ll int>> mp;
        
        fori(0,n) cin>>x, mp[x].pb(i+1);
        
        // if same element is there in whole set
        if(mp.size()==1){
            fori(0,n) cout<<x<<" ";
            NL
            continue;
        }
        
        vector<ll int> answer(n+1,INT_MAX);
        
        for(auto k: mp){
            ll int diff = 0;
            ll int e = k.first;
            
            fori(0,k.second.size()-1){
                ll int d = k.second[i+1]-k.second[i];
                diff = max(diff,d);
            }
            
            diff = max({diff, k.second[0], n-k.second[k.second.size()-1]+1});
            answer[diff] = min({answer[diff], e});
        }
        
        ll int mini = INT_MAX;
        
        fori(1,n+1){
            mini = min({mini, answer[i]});
            answer[i] = mini;
            if(answer[i]==INT_MAX) cout<<"-1 ";
            else cout<<answer[i]<<" ";
        }
        NL
    }
    
	return 0;
}