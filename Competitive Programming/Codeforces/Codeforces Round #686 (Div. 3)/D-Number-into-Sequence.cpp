// Question: https://codeforces.com/contest/1454/problem/D
// Solution: https://codeforces.com/contest/1454/submission/99528839

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

ll int power(ll int base,ll int power){
    ll int res = 1;
    while(power){
        if(power&1){
            res *= base;
            power--;
        }else{
            base *= base;
            power/=2;
        }
    }
    
    return res;
}

int main(){
    optimize
    /////// Write from here
    
    tests{
        vector<pair<ll int, ll int>> vvvv;
        ll int n; cin>>n;
        ll int num = n;
        for(ll int i=2;i*i<=n;i++){
            if(n%i==0){
                ll int countp=0;
                while(n%i==0) countp++, n/=i;
                vvvv.push_back(
                    make_pair(countp, i)
                );
            }
        }
        
        vvvv.push_back(
            make_pair(1,num)
        );
        
        sort(vvvv.rbegin(),vvvv.rend());
 
        ll int count = vvvv[0].first , factor = vvvv[0].second;
        
        if(count==1) cout<<"1\n"<<num;
        else{
            cout<<count<<"\n";
            ll int maxd=1;
            for(ll int i=0;i<count-1;i++){
                cout<<factor<<" ";
                maxd *= factor;
            }
            cout<<num/maxd;
        }
        NL
    }
    
	return 0;
}