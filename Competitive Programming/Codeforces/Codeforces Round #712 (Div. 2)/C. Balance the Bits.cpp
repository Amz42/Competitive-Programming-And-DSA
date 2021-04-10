// Question: https://codeforces.com/contest/1504/problem/C
// Solution: https://codeforces.com/contest/1504/submission/112465283

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
	int n; cin >> n;
	string s; cin >> s;
	int _1 = 0, _0 = 0;

	for (auto k : s) (k == '0' ? _0++ : _1++);

	if (_0 & 1 || _1 & 1 || s[0] == '0' || s[n - 1] == '0') {
		cout << "NO"; NL
		return;
	}

	string a = "", b = "";
	int x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			a += (x < _1 / 2 ? '(' : ')');
			b += (x < _1 / 2 ? '(' : ')');
			x++;
		} else {
			a += (y % 2 ? '(' : ')');
			b += (y % 2 ? ')' : '(');
			y++;
		}
	}

	cout << "YES"; NL
	cout << a; NL
	cout << b; NL
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