// Question: https://codeforces.com/contest/1452/problem/D
// Solution: https://codeforces.com/contest/1452/submission/99641054

/*                                              _                    _  _  ____
                                               / \   _ __ ___  ____ | || ||___ \
                                              / _ \ | '_ ` _ \|_  / | || |_ __) |
                                             / ___ \| | | | | |/ /  |__   _/ __/
                                            /_/   \_\_| |_| |_/___|    |_||_____|
*/
#include <bits/stdc++.h>
#define ll          long long
#define optimize    ios::sync_with_stdio(0);cin.tie(0);
#define MOD         (int)(998244353)
using namespace std;

ll int n;

ll int Power(ll int base, ll int power){
    ll int res = 1;
    while(power){
        if(power&1){
            res = (res*base) % MOD;
            power--;
        }else{
            base = (base*base) % MOD;
            power/=2;
        }
    }
    return res;
}

ll int modinv(ll int x, ll int mod) {
	return Power(x, mod - 2);
}

int main(){
    optimize
    /////// Write from here
    
    cin>>n;
    ll int x,y,z; x = y = z = 1;
    for(int i=3;i<=n;i++){
        z = (x+y) % MOD;
        x = y;
        y = z;
    }
    
    ll int numerator = z;
    ll int denominator = Power(modinv(2, MOD), n);
    
    ll int answer = (numerator * denominator) % MOD;
	answer += MOD; answer %= MOD;
	cout<<answer<<"\n";
    
	return 0;
}