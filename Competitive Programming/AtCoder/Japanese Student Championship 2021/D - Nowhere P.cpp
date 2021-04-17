// Question: https://atcoder.jp/contests/jsc2021/tasks/jsc2021_d
// Solution: https://atcoder.jp/contests/jsc2021/submissions/21820236

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


long long int power(long long int base, long long int _power, long long int _mod = LLONG_MAX) {
	long long int result = 1;
	base %= _mod;
	while (_power > 0) {
		if (_power & 1) result = (result * base) % _mod;
		_power = _power >> 1;
		base = (base * base) % _mod;
	}
	return result;
}

ll int n, p;

void solve() {
	cin >> n >> p;
	cout << ((p - 1) % MOD * power(p - 2, n - 1, MOD) % MOD ) % MOD;
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