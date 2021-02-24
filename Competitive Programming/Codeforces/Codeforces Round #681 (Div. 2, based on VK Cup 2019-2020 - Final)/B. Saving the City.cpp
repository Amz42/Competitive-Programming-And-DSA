// Question: https://codeforces.com/contest/1443/problem/B
// Solution: https://codeforces.com/contest/1443/submission/97460951

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
        ll int a,b;  string s;
        cin>>a>>b>>s;
        ll int answer = INT_MAX;
        
        vector<int> z;
        ll int aseg = 0;
        ll int n = s.size();
        for(ll int i=0; i<n;){
            if(s[i]=='0'){
                ll int sm = 0;
                while(i<n && s[i]=='0') sm++, i++;
                z.pb(sm);
            }else{
                while(i<n && s[i]=='1') i++;
                aseg++;
            }
        }
        
        
        // cout<<aseg<<" "; NL
        // for(auto k: z) cout<<k<<" ";
        // NL NL
        
        if(s[0]=='0') z[0]=INT_MAX;
        if(s[n-1]=='0') z[z.size()-1] = INT_MAX;
        
        sort(z.begin(), z.end());
        answer = aseg*a;
        ll int bcoff = 0;
        for(auto k: z){
            aseg--;
            bcoff += k;
            answer = min(answer, aseg*a + bcoff*b );
        }
        
        
        cout<<answer;
        NL
    }
    
	return 0;
}