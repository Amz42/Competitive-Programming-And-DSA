// Question: https://codeforces.com/contest/1512/problem/C
// Solution: https://codeforces.com/contest/1512/submission/112581134

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






void solve() {
	int a, b; cin >> a >> b;
	int x = a, m = b;
	string s; cin >> s;

	int n = s.size();
	for (int i = 0; i < n / 2; i++) {
		if (s[i] != '?' && s[n - i - 1] != '?' && s[i] != s[n - i - 1]) {
			cout << "-1"; NL
			return;
		}

		if (s[i] == '?' && s[n - i - 1] != '?') s[i] = s[n - i - 1];
		if (s[i] != '?' && s[n - i - 1] == '?') s[n - i - 1] = s[i];
	}

	a = x;
	b = m;

	for (int i = 0; i < n; i++) {
		if (s[i] == '0') a--;
		if (s[i] == '1') b--;
	}

	if (a < 0 || b < 0) {
		cout << "-1"; NL
		return;
	}

	for (int i = 0; i < n / 2; i++) {
		if (s[i] == '?' && s[n - i - 1] == '?') {
			if (a >= 2) {
				s[i] = s[n - i - 1] = '0';
				a -= ( i == n - i - 1 ? 1 : 2);
			} else if (b >= 2) {
				s[i] = s[n - i - 1] = '1';
				b -= ( i == n - i - 1 ? 1 : 2);
			} else {
				cout << "-1"; NL
				return;
			}
		}
	}

	if (n & 1) {
		if (a) s[n / 2] = '0', a--;
		else if (b) s[n / 2] = '1', b--;
	}



	if (a != 0 || b != 0) {
		cout << "-1"; NL
		return;
	}

	a = 0;
	b = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] == '0') a++;
		if (s[i] == '1') b++;
		if (s[i] == '?') {
			cout << "-1"; NL
			return;
		}
	}

	if (a != x || b != m) {
		cout << "-1"; NL
		return;
	}

	cout << s; NL
	return;
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