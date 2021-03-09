// Question: https://codeforces.com/contest/1420/problem/C1
// Solution: https://codeforces.com/contest/1420/submission/96791294

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

ll int n, q, answer=0;
ll int a[3'00'005];

void Update(int index){
    if(a[index-1]<a[index] && a[index]>a[index+1]) answer += a[index]; //maxima
    if(a[index-1]>a[index] && a[index]<a[index+1]) answer -= a[index]; //minima
}

void Remove(int index){
    if(a[index-1]<a[index] && a[index]>a[index+1]) answer -= a[index]; //maxima
    if(a[index-1]>a[index] && a[index]<a[index+1]) answer += a[index]; //minima
}


int main(){
    optimize
    /////// Write from here
    
    tests{
        answer = 0;
        cin>>n>>q;
        fori(1,n+1) cin>>a[i];
        a[0] = a[n+1] = 0;
        fori(1,n+1) Update(i);
        
        cout<<answer; NL
        
        while(q--){
            ll int l,r; cin>>l>>r;
            set<ll int> affected;
            
            for(int j=-1;j<=1;j++){
                int e1 = l+j;
                int e2 = r+j;
                
                if( 0<e1 && e1<n+1 ) affected.insert(e1);
                if( 0<e2 && e2<n+1 ) affected.insert(e2);
            }
            
            for(auto k: affected) Remove(k);
            swap(a[l],a[r]);
            for(auto k: affected) Update(k);
            
            cout<<answer; NL
        }
    }    
    
	return 0;
}