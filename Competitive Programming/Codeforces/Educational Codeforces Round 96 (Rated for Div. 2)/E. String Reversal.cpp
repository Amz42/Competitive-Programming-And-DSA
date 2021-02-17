// Question: https://codeforces.com/contest/1430/problem/E
// Solution: https://codeforces.com/contest/1430/submission/95371559

/*                                      _                    _  _  ____
                                       / \   _ __ ___  ____ | || ||___ \
                                      / _ \ | '_ ` _ \|_  / | || |_ __) |
                                     / ___ \| | | | | |/ /  |__   _/ __/
                                    /_/   \_\_| |_| |_/___|    |_||_____|
*/
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

const int N = 2*ten5+2;
ll int pref[N]={0};

void update(int i, int add){
    while(i<N){
        pref[i] += add;
        i += (i&(-i));
    }
}

ll int sum(int i){
    ll int s = 0;
    while(i>0){
        s += pref[i];
        i -= (i&(-i));
    }
    return s;
}

ll int query(int l, int r){
    return sum(r) - sum(l-1);
}

int main(){
    optimize
    /////// Write from here
    
    int n; cin>>n;
    string s; cin>>s;
    
    queue<int> q[26];
    
    fori(n){
        char c = s[n-i-1];
        q[c-'a'].push(i+1);
    }
    
    ll int answer=0;
    fori(n){
        int k = q[s[i]-'a'].front();
        q[s[i]-'a'].pop();
        
        answer += query(k,n);
        update(k,1);
    }
    
    cout<<answer;
    
	return 0;
}