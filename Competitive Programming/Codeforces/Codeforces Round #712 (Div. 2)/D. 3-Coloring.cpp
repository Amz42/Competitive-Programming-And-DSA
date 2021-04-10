// Question: https://codeforces.com/contest/1504/problem/D
// Solution: https://codeforces.com/contest/1504/submission/112572270

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
	vector<pair<int, int>> v[3];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			v[((i + j) & 1) + 1].push_back({i, j});

	for (int i = 0; i < n * n; i++) {
		int alice; cin >> alice;
		int color, cell;

		if (alice == 1) {
			if (v[2].size()) {
				color = 2;
				cell = 2;
			} else {
				color = 3;
				cell = 1;
			}
		} else if (alice == 2) {
			if (v[1].size()) {
				color = 1;
				cell = 1;
			} else {
				color = 3;
				cell = 2;
			}
		} else if (alice == 3) {
			if (v[1].size()) {
				color = 1;
				cell = 1;
			} else {
				color = 2;
				cell = 2;
			}
		}

		auto p = v[cell].back(); v[cell].pop_back();
		cout << color << " " << p.first << " " << p.second << endl;
		cout.flush();
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