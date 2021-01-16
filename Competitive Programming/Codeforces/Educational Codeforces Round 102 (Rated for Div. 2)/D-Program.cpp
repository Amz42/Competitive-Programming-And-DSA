// Question: https://codeforces.com/contest/1473/problem/D
// Solution: https://codeforces.com/contest/1473/submission/104500067

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
	int n, query; cin >> n >> query;
	string s; cin >> s;
	int a[n];

	for (int i = 0; i < n; i++) {
		a[i] = (s[i] == '-' ? -1 : +1);
		if (i) a[i] += a[i - 1];
	}

	int prefMin[n], prefMax[n], suffMin[n], suffMax[n];
	for (int i = 0, j = n - 1; i < n; i++, j--) {
		prefMin[i] = prefMax[i] = a[i];
		suffMin[j] = suffMax[j] = a[j];

		if (i) {
			prefMin[i] = min(prefMin[i], prefMin[i - 1]);
			prefMax[i] = max(prefMax[i], prefMax[i - 1]);
			suffMin[j] = min(suffMin[j], suffMin[j + 1]);
			suffMax[j] = max(suffMax[j], suffMax[j + 1]);
		}
	}

	while (query--) {
		int l, r; cin >> l >> r; l--, r--;

		int loss = a[r] - (l ? a[l - 1] : 0);

		int pmax = (l ? prefMax[l - 1] : 0); int pmin = (l ? prefMin[l - 1] : 0);
		pmax = max(0, pmax);
		pmin = min(0, pmin);

		int sMax = (r < n - 1 ? suffMax[r + 1] : 0); int sMin = (r < n - 1 ? suffMin[r + 1] : 0);
		if (r < n - 1) {
			sMax -= loss;
			sMin -= loss;
		}

		cout << max(pmax, sMax) - min(pmin, sMin) + 1; NL
	}
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