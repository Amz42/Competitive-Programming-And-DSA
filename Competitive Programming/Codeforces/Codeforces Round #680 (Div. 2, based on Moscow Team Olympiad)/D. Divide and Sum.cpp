// Question: https://codeforces.com/contest/1445/problem/D
// Solution: https://codeforces.com/contest/1445/submission/99780890

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
#define MOD         (int)(998244353)
#define ten5        (int)(1e5)
#define all(v)      v.begin(),v.end()
#define sort_d(v)   sort(all(v),greater<ll int>());
#define maxv(v)     *max_element(all(v))
using namespace std;

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

unsigned long long nCrModPFermat(unsigned long long n, int r, int p) {
	if (n < r) return 0;
	if (r == 0) return 1;
	unsigned long long fac[n + 1];
	fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
	return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}


void solve() {
	ll int n; cin >> n;
	vector<int> a(2 * n); for (int i = 0; i < 2 * n; i++) cin >> a[i];
	sort(a.begin(), a.end());

	// for (auto k : a) cout << k << " "; NL

	ll int x = 0, y = 0;
	for (int i = 0; i < n; i++) x += a[i];
	for (int i = 0; i < n; i++) y += a[i + n];

	cout << (((y - x) % MOD) * (nCrModPFermat(2 * n, n, MOD) % MOD) ) % MOD;
}


int main() {
	optimize
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	long long int tests = 1;

	// cin >> tests;

	for (ll int test_case = 1; test_case <= tests; test_case++) {
		solve();
	}

	cerr << "Execution Time : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}