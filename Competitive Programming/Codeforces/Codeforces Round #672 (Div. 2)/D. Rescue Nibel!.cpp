// Question: https://codeforces.com/contest/1420/problem/D
// Solution: https://codeforces.com/contest/1420/submission/96809609

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
#define MOD         998'244'353
#define ten5        1e5
#define all(v)      v.begin(),v.end()
#define sort_d(v)   sort(all(v),greater<ll int>());
#define maxv(v)     *max_element(all(v))
#define LOWCASE(s)  transform(all(s),s.begin(),::tolower);
#define UPCASE(s)   transform(all(s),s.begin(),::toupper);
#define setbits(b)  __builtin_popcount(b);
#define tests       ll int t;cin>>t;while(t--)
using namespace std;


const int N = 3'00'001;
ll int n,k;
ll int fact[N];
ll int mult(ll int a, ll int b){return (a*b)%MOD;}

unsigned long long power(unsigned long long x, int y, int p){
	unsigned long long res=1;
	x = x%p;
	while (y > 0){
		if (y & 1) res = (res * x) % p;
		y = y >> 1;
		x = (x * x) % p;
	}
	return res; 
} 

unsigned long long modInverse(unsigned long long n, int p){ return power(n, p-2, p);}
unsigned long long nCrModPFermat(unsigned long long n,int r, int p){
	if (r==0)return 1;
	return (fact[n] * modInverse(fact[r], p) % p * modInverse(fact[n - r], p) % p) % p; 
}


int main(){
    optimize
    /////// Write from here
    
    fact[0]=fact[1]=1;
    fori(2,N+1){ fact[i] = mult(i, fact[i-1]); }
    
    cin>>n>>k;
    
    vector<pair<ll int, int>> v;
    
    ll int l,r;
    fori(0,n){
        cin>>l>>r;
        v.pb({l,0});
        v.pb({r,1});
    }
    
    sort(v.begin(),v.end());
    
    ll int onn = 0, answer=0;
    
    for(auto g: v){
        bool on = !g.second;
        if(on){
            answer += ( onn>=k-1 ? nCrModPFermat(onn, k-1, MOD) : 0 );
            answer %= MOD;
            onn++;
        }else onn--;
    }
    
    cout<<answer;
    
	return 0;
}