// Question: https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/explosions-810e1162/
// Solution: https://www.hackerearth.com/submission/56953088/

/*                                              _                    _  _  ____
                                               / \   _ __ ___  ____ | || ||___ \
                                              / _ \ | '_ ` _ \|_  / | || |_ __) |
                                             / ___ \| | | | | |/ /  |__   _/ __/
                                            /_/   \_\_| |_| |_/___|    |_||_____|
*/
#include <bits/stdc++.h>
#define ll          long long
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
using namespace std;
 
 
 
// const int fact_N = (int)(2e5 + 5);
// long long factorialNumInverse[fact_N], naturalNumInverse[fact_N], fact[fact_N];
// void InverseofNumber(long long p) {
//     naturalNumInverse[0] = naturalNumInverse[1] = 1;
//     for (ll int i = 2; i <= fact_N; i++)
//         naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
// }
// void InverseofFactorial(long long p) {
//     factorialNumInverse[0] = factorialNumInverse[1] = 1;
//     for (ll int i = 2; i <= fact_N; i++)
//         factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
// }
// void factorial(long long p) {
//     fact[0] = 1;
//     for (ll int i = 1; i <= fact_N; i++) {
//         fact[i] = (fact[i - 1] * i) % p;
//     }
// }
// long long nCr(long long fact_N, long long R, long long p) {
//     long long ans = ((fact[fact_N] * factorialNumInverse[R]) % p * factorialNumInverse[fact_N - R]) % p;
//     return ans;
// }
// // call "precompute" function at the start of the program inside main()
// void precompute(long long int mod = (long long int)(1e9 + 7)) {
//     InverseofNumber(mod);
//     InverseofFactorial(mod);
//     factorial(mod);
// }
 
unsigned long long power(unsigned long long x, int y, int p) {
    unsigned long long res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
unsigned long long modInverse(unsigned long long n, int p) {
    return power(n, p - 2, p);
}
unsigned long long ncr(unsigned long long n, int r, int p) {
    if (n < r) return 0;
    if (r == 0) return 1;
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)fac[i] = (fac[i - 1] * i) % p;
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}
 
 
void solve(int tc) {
    ll n, k; cin >> n >> k;
 
    ll int x;
    ll int od = 0, ev = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x & 1) od++;
        else ev++;
    }
 
    ll int answer = 0;
    for (ll int i = 1; i <= k; i += 2) {
        if ( od >= i and ev >= k - i) {
            ll int g = ncr(od, i, MOD) % MOD;
            ll int f = ncr(ev, k - i, MOD) % MOD;
 
            answer += (g * f) % MOD;
            answer %= MOD;
        }
    }
 
    cout << answer; NL
}
 
 
 
 
 
 
int main() {
    optimize
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    // precompute(MOD);
 
    long long int tests = 1;
 
    cin >> tests;
 
    for (ll int test_case = 1; test_case <= tests; test_case++) {
        solve(test_case);
    }
 
    // cerr << "Execution Time : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}