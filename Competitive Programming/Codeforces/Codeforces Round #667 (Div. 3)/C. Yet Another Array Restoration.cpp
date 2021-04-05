// Question: https://codeforces.com/contest/1409/problem/C
// Solution: https://codeforces.com/contest/1409/submission/91889289

#include <bits/stdc++.h>
#define ll long long
#define u_map unordered_map
#define sht short
#define pb push_back
#define mkpr make_pair
#define NL cout<<"\n";
#define optimize ios::sync_with_stdio(0);cin.tie(0);
#define PI 3.14159265358979323846
#define fori(n) for(ll int i=0;i<(ll int)n;i++)
#define forj(n) for(ll int j=0;j<(ll int)n;j++)
#define MOD 1'000'000'007
#define ten5 1'00'000
#define all(v) v.begin(),v.end()
#define sort_a(v) sort(all(v));
#define sort_d(v) sort(all(v),greater<ll int>());
#define maxv(v) *max_element(all(v))
#define LOWCASE(s) transform(all(s),s.begin(),::tolower);
#define UPCASE(s) transform(all(s),s.begin(),::toupper);
#define setbits(b) __builtin_popcount(b);
#define tests ll int t;cin>>t;while(t--)
using namespace std;
void swap(int *x,int *y){*x^=*y;*y^=*x;*x^=*y;}
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
        ll int n,x,y; cin>>n>>x>>y;
        ll int div=1;
        vector<int> v; v.pb(x);
        
        for(int i = n-1;i>=1;i--){
            if((y-x)%i==0){
                div=i;
                break;
            }
        }
        
        ll int tba = (y-x)/div;
        
        if(div==1 && y-x-1==n-2){
            fori(y-x-1) v.pb(*v.rbegin()+1);
        }
        
        fori(div-1){
            v.pb(*v.rbegin()+tba);
        }
        v.pb(y);
        
        while(v.size()<n && x-tba>0){
            x -= tba;
            v.pb(x);
        }
        
        while(v.size()<n){
            y += tba;
            v.pb(y);
        }
        
        for(auto k: v) cout<<k<<" ";
        NL
    }
    
	return 0;
}