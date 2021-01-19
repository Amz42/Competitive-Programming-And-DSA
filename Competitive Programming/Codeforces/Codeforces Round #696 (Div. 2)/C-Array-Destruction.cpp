// Question: https://codeforces.com/contest/1474/problem/C
// Solution: https://codeforces.com/contest/1474/submission/104846473

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
	int n; cin >> n; n <<= 1;
	vector<int> v(n); fori(0, n) cin >> v[i];
	sort(v.begin(), v.end());

	if (n == 2) {
		cout << "YES\n";
		cout << v[0] + v[1]; NL
		cout << v[0] << " " << v[1]; NL
		return;
	}

	for (int i = n - 2; i >= 0; i--) {
		multiset<int> ms;
		vector<pair<int, int>> answer;

		int X = v[n - 1];
		bool YES = true;
		forj(0, n - 1) if (i != j) ms.insert(v[j]);

		while (!ms.empty()) {
			int max_num = *ms.rbegin(); ms.erase(ms.find(max_num));
			auto it = ms.find(X - max_num);
			if (it != ms.end()) {
				answer.pb({max_num, X - max_num});
				ms.erase(it);
				X = max_num;
			} else {
				YES = false;
				break;
			}
		}

		if (YES) {
			cout << "YES\n";
			cout << v[n - 1] + v[i] << "\n";
			cout << v[n - 1] << " " << v[i] << "\n";
			for (auto k : answer) cout << k.first << " " << k.second << "\n";
			return;
		}
	}

	cout << "NO\n";
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