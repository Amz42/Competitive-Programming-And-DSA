// Question: https://codeforces.com/contest/1516/problem/B
// Solution: https://codeforces.com/contest/1516/submission/113766576

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






void solve(int tc) {
	int n; cin >> n;

	ll int pref[n], suff[n], a[n];
	for (int i = 0; i < n; i++) cin >> pref[i], a[i] = suff[i] = pref[i];

	for (int i = 1; i < n; i++) pref[i] = pref[i] ^ pref[i - 1];
	for (int j = n - 2; j >= 0; j--)	suff[j] = suff[j] ^ suff[j + 1];

	ll int xr = pref[n - 1];

	if (xr == 0) {
		for (int i = 0; i < n - 1; i++) {
			if (pref[i] == suff[i + 1]) {
				cout << "YES"; NL
				return;
			}
		}
	} else {
		ll int nxr = 0;
		int i = 0, c = 0;
		while (i < n) {
			while (i < n && a[i] == xr) i++, c++;
			while (i < n && nxr != xr) nxr ^= a[i++];
			if (nxr == xr) nxr = 0, c++;
		}
		if (c > 1 && nxr == 0) {
			cout << "YES"; NL
			return;
		}
	}


	cout << "NO"; NL
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
		solve(test_case);
	}

	// cerr << "Execution Time : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}