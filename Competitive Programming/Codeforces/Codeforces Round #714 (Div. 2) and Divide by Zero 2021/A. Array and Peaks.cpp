// Question: https://codeforces.com/contest/1513/problem/A
// Solution: https://codeforces.com/contest/1513/submission/112669761

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
	ll int n, k; cin >> n >> k;

	if (n == 2 && k == 1) {
		cout << "-1"; NL
		return;
	}

	if (k == 0) {
		for (int i = 1; i <= n; i++) cout << i << " ";
		NL return;
	}

	vector<ll int> v(n);
	for (int i = 0; i < n; i++) v[i] = i + 1;

	int x = 1, p = k;
	while (p-- && x + 1 < n) {
		swap(v[x], v[x + 1]);
		x += 2;
	}

	int peaks = 0;
	for (int i = 1; i < n - 1; i++) {
		if (v[i - 1] < v[i] && v[i] > v[i + 1])
			peaks++;
	}

	if (peaks != k) {
		cout << "-1";
	} else {
		for (auto k : v) cout << k << " ";
	}
	NL
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