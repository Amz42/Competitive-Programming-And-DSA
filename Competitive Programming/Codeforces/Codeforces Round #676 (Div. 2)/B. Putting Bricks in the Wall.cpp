// Question: https://codeforces.com/contest/1421/problem/B
// Solution: https://codeforces.com/contest/1421/submission/95872917

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
#define PI          3.14159265358979323846
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
        ll int n; cin>>n;
        char x;
        int m[n][n];
        fori(0,n){
            forj(0,n){
                cin>>x; m[i][j] = x - '0';
            }
        }
        
        int a = m[0][1] - '0'; 
        int b = m[1][0] - '0';
        int c = m[n-1][n-2] - '0';
        int d = m[n-2][n-1] - '0';
        
        vector<pair<int,int>> ans;
        
        if(a==b && c==d && a!=c){
            cout<<0; NL
        }else{
            if(c==d && a!=b){
                if(a==c) a=m[0][1]=!c, ans.pb({1,2});
                if(b==c) b=m[1][0]=!c, ans.pb({2,1});
            }
            
            if(a==b && c!=d){
                if(c==a) c=m[n-1][n-2]=!a, ans.pb({n,n-1});
                if(d==a) d=m[n-2][n-1]=!a, ans.pb({n-1,n});
            }
            
            if(a!=b && c!=d){
                a=m[0][1]=b, ans.pb({1,2});
                
                if(c==a) c=m[n-1][n-2]=d, ans.pb({n,n-1});
                else     d=m[n-2][n-1]=c, ans.pb({n-1,n});
            }
            
            if(a==b && c==d && a==c){
                c=m[n-1][n-2]=!a, ans.pb({n,n-1});
                d=m[n-2][n-1]=!a, ans.pb({n-1,n});
            }
            
            cout<<ans.size(); NL
            for(auto k:ans){cout<<k.first<<" "<<k.second; NL}
        }
        
    }
    
	return 0;
}