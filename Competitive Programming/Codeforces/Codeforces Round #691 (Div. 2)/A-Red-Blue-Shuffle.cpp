// Question: https://codeforces.com/contest/1459/problem/A
// Solution: https://codeforces.com/contest/1459/submission/101723500

#include <bits/stdc++.h>
#define ll          long long 
 
using namespace std;

int main(){
    int test; cin>>test;
    while(test--){
        ll n; cin>>n;
        string a,b; cin>>a>>b;
        int an=0,bn=0;

        for(ll i=0;i<n;i++){
            if((a[i]-'0') > (b[i]-'0')) an++;
            else if((a[i]-'0') < (b[i]-'0')) bn++;
    
        }
        if(an>bn) cout<<"RED"<<endl;
        else if(bn>an) cout<<"BLUE"<<endl;
        else cout<<"EQUAL"<<endl;
    }    
    
    return 0;
}