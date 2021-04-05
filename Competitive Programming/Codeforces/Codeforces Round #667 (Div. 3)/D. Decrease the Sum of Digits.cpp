// Question: https://codeforces.com/contest/1409/problem/D
// Solution: https://codeforces.com/contest/1409/submission/100278665

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

long long int power(long long int base, long long int _power, long long int _mod = 1e9 + 7) {
	long long int result = 1;
	base %= _mod;
	while (_power > 0) {
		if (_power & 1) result = (result * base) % _mod;
		_power = _power >> 1;
		base = (base * base) % _mod;
	}
	return result;
}

ll int sum_of_digit(ll int n) {
	ll int answer = 0;
	while (n) {
		answer += n % 10;
		n /= 10;
	}
	return answer;
}

ll int moves(ll int n) {
	return (10 - n) % 10;
}

void solve() {
	ll int n; cin >> n;
	int s; cin >> s;

	ll int answer = 0;

	for (int i = 0; i < 18; i++) {
		if (sum_of_digit(n) <= s) break;
		ll int digit = (n / (ll int)power(10, i, LLONG_MAX)) % 10;
		ll int x = (moves(digit) * power(10, i, LLONG_MAX));
		answer += x;
		n += x;
		// cout << x << " ";
	}

	// NL

	cout << answer;
	NL
}






int main() {
	optimize
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	long long int tests = 1;

	cin >> tests;

	for (ll int test_case = 1; test_case <= tests; test_case++) {
		solve();
	}

	cerr << "Execution Time : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}