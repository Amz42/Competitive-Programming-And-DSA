// Question: https://codeforces.com/contest/1484/problem/B
// Solution:https://codeforces.com/contest/1484/submission/111355041

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
	set<int> diff;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];

	// if <= 2 elements then 'm' is undeterminable
	if (n <= 2) {
		cout << "0"; NL
		return;
	}

	int mx = a[0];
	for (int i = 1; i < n; i++) {
		mx = max(mx, a[i]);
		diff.insert(a[i] - a[i - 1]);
	}

	// if only one diff is there then 'm' is undeterminable
	if (diff.size() == 1) {
		cout << "0"; NL
		return;
	}

	// if more than 2 differences there then m is not possible
	if (diff.size() > 2) {
		cout << "-1"; NL
		return;
	}

	int x = *diff.begin(); diff.erase(diff.begin());
	int y = *diff.begin(); diff.erase(diff.begin());

	// if both diff are +tive or both -tive or max element is greater than sum of diffs
	// then 'm' is not possible
	if (
	    (x >= 0 && y >= 0) ||
	    (x <= 0 && y <= 0) ||
	    (mx > abs(x) + abs(y))
	) {
		cout << "-1"; NL
		return;
	}

	cout << abs(x) + abs(y) << " " << y; NL
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