// Question: https://www.codechef.com/problems/DELISH
// Solution: https://www.codechef.com/viewsolution/44644684

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



vector<array<ll int, 2>> fun(vector<ll int>& v) {
	int n = v.size();
	vector<array<ll int, 2>> a(n);

	ll int mxeh = 0, mx = INT_MIN;
	ll int mneh = 0, mn = INT_MAX;

	for (int i = 0; i < n; i++) {
		mxeh = max(mxeh + v[i], v[i]);
		mneh = min(mneh + v[i], v[i]);

		mx = max(mx, mxeh);
		mn = min(mn, mneh);

		a[i][0] = mx;
		a[i][1] = mn;
	}

	return a;
}

void solve() {
	int n; cin >> n;
	vector<ll int> v(n); for (auto &k : v) cin >> k;

	auto x = fun(v);
	reverse(v.begin(), v.end());
	auto y = fun(v);
	reverse(y.begin(), y.end());

	ll int answer = 0;
	for (int i = 0; i < n - 1; i++) {
		answer = max({
			answer,
			abs(y[i + 1][0] - x[i][1]),
			abs(y[i + 1][1] - x[i][0]),
		});
	}

	cout << answer; NL
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