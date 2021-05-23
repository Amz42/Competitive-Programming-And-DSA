// Question: https://codeforces.com/contest/1392/problem/A
// Solution: https://codeforces.com/contest/1392/submission/102029641

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
	int n, mx = 0; cin >> n;
	vector<int>	v(n);
	map<ll int, ll int> mp;
	fori(0, n) {
		cin >> v[i];
		mx = max(mx, v[i]);
		mp[v[i]]++;
	}

	fori(0, n) {
		if (
		    v[i] == mx &&
		    (
		        (i > 0 && v[i - 1] != mx)	||
		        (i < n - 1 && v[i + 1] != mx)
		    )
		) {
			cout << "1"; NL
			return;
		}
	}

	cout << mp[mx]; NL
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