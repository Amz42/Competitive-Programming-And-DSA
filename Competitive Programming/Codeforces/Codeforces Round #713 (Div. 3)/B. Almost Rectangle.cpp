// Question: https://codeforces.com/contest/1512/problem/B
// Solution: https://codeforces.com/contest/1512/submission/112501287

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
	char m[n][n];
	vector<pair<int, int>> p;

	char ch;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ch;
			m[i][j] = ch;
			if (ch == '*') {p.push_back({i, j});}
		}
	}


	sort(p.begin(), p.end());

	if (p[0].first == p[1].first) { // row same
		if (p[0].first + 1 < n) {
			p.push_back({p[0].first + 1, p[0].second});
			p.push_back({p[1].first + 1, p[1].second});
			// cout << "yes";
		} else {
			p.push_back({p[0].first - 1, p[0].second});
			p.push_back({p[1].first - 1, p[1].second});
			// cout << "npo";
		}
	} else if (p[0].second == p[1].second) { // col same
		if (p[0].second + 1 < n) {
			p.push_back({p[0].first, p[0].second + 1});
			p.push_back({p[1].first, p[1].second + 1});
		} else {
			p.push_back({p[0].first, p[0].second - 1});
			p.push_back({p[1].first, p[1].second - 1});
		}
	} else {
		p.push_back({p[0].first, p[1].second});
		p.push_back({p[1].first, p[0].second});
	}

	for (auto k : p) {
		m[k.first][k.second] = '*';
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << m[i][j];
		}
		NL;
	}
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