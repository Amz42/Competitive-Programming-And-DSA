// Question: https://codeforces.com/contest/1484/problem/C
// Solution: https://codeforces.com/contest/1484/submission/110644095

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
	int n, m, x, k; cin >> n >> m;
	int available[m] = {0};
	vector<int> day[m];
	int frnd[n + 1] = {0};
	int selected[n + 1] = {0};

	for (int i = 0; i < m; i++) {
		cin >> x; available[i] = x;
		for (int j = 0; j < x; j++) {
			cin >> k; day[i].push_back(k);
			frnd[k]++;
		}
	}

	set<pair<int, int>> s;
	for (int i = 0; i < m; i++) s.insert(make_pair(available[i], i));

	int answer[m];
	for (auto p : s) {
		int dy = p.second;
		// cout << "day: " << dy << "\n";
		int prson = -1, avl = -1;
		for (int i = 0; i < available[dy]; i++) {
			if (selected[day[dy][i]] < (m + 1) / 2 && ((prson == -1 || (frnd[day[dy][i]] < avl) ))) {
				prson = day[dy][i], avl = frnd[day[dy][i]];
			} else frnd[day[dy][i]]--;
		}

		if (prson == -1) {
			cout << "NO"; NL
			return;
		}

		answer[dy] = prson;
		frnd[prson]--;
		selected[prson]++;
	}

	cout << "YES"; NL
	for (auto w : answer) cout << w << " "; NL
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