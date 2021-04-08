// Question: https://codeforces.com/problemset/problem/777/C
// Solution: https://codeforces.com/contest/777/submission/112297340

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
	int n, m; cin >> n >> m;

	int a[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	set<int> pc[n + 1];

	for (int j = 0; j < m; j++) {
		pc[1].insert(1);
		int cnt = 1;
		for (int i = 1; i < n; i++) {
			if (a[i - 1][j] > a[i][j]) cnt = 0;
			cnt++;
			pc[i + 1].insert(cnt);
		}
	}

	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r;
		auto it = pc[r].lower_bound(r - l + 1);
		cout << (it == pc[r].end() ? "No" : "Yes"); NL
	}
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