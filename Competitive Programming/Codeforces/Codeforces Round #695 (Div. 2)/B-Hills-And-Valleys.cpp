// Question: https://codeforces.com/problemset/problem/1467/B
// Solution: https://codeforces.com/contest/1467/submission/103820810

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
	int answer = 0;
	vector<int> v(n); for (auto &k : v) cin >> k;

	function<bool(int)> isValleyOrHill = [&](int index) {
		if (index == 0 || index == n - 1) return false;
		return (
		           (v[index - 1] < v[index] && v[index] > v[index + 1]) ||
		           (v[index - 1] > v[index] && v[index] < v[index + 1])
		       );
	};

	fori(0, n) answer += isValleyOrHill(i);

	int minus = 0;
	fori(0, n) {
		if (isValleyOrHill(i)) {
			int original = v[i];
			int adjacent_initial_state = isValleyOrHill(i - 1) + isValleyOrHill(i + 1);

			v[i] = v[i - 1]; // make equal to left
			minus = max(adjacent_initial_state - isValleyOrHill(i + 1) + 1, minus);

			v[i] = v[i + 1]; // make equal to right
			minus = max(adjacent_initial_state - isValleyOrHill(i - 1) + 1, minus);

			v[i] = original;
		}
	}

	cout << answer - minus; NL
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