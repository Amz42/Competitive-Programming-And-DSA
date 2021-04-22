// Question: https://codeforces.com/contest/1400/problem/B
// Solution: https://codeforces.com/contest/1400/submission/90998870

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
struct hash_pair{
    template<class T1,class T2> 
    size_t operator()(const pair<T1,T2>& p)const{
        auto h1=hash<T1>{}(p.first);
        auto h2=hash<T2>{}(p.second); 
        return h1^h2;
    }
};

void swap(int *x,int *y){*x^=*y; *y^=*x; *x^=*y;}
int main(){
    optimize
    /////// Write from here
    
    tests{
        int mcap,fcap,cnts,cntx,ws,wx,ans=0;
        cin>>mcap>>fcap>>cnts>>cntx>>ws>>wx;
        
        if(mcap>fcap) swap(&mcap,&fcap);
        if(wx<ws){
            swap(&wx,&ws);
            swap(&cntx,&cnts);
        }
        
        fori(cnts+1){
            if(mcap<i*ws) break;
            //my swords
            int totwp = i;
            int mcapt = mcap-i*ws;
            //my axes
            int mx = min(cntx,mcapt/wx);
            totwp += mx;
            
            // fcap swords
            int ks = min((int)(cnts-i),fcap/ws);
            // fcap remaining capacity
            int fcapt = fcap-ks*ws;
            // fcap axes
            int fx = min(cntx-mx,fcapt/wx);
            totwp += ks+fx;
            ans = max(ans,totwp);
        }
        
        cout<<ans;
        NL
    }
    
	return 0;
}