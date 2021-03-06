// Question: https://atcoder.jp/contests/abc194/tasks/abc194_b
// Solution: https://atcoder.jp/contests/abc194/submissions/20704135

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
	vector<int> a;
	vector<pair<int, int>> b;

	fori(0, n) {
		int x, y; cin >> x >> y;
		a.pb(x); b.push_back(make_pair(y, i));
	}

	sort(b.begin(), b.end());

	int answer = INT_MAX;

	fori(0, n) {
		if (b[0].second == i) {
			answer = min(answer, a[i] + b[0].first);
			answer = min(answer, max(a[i], b[1].first));
		} else {
			answer = min(answer, max(a[i], b[0].first));
		}
	}

	cout << answer;
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