// Question: https://codeforces.com/contest/1462/problem/E1
// Solution: https://codeforces.com/contest/1462/submission/101417338

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


ll int ncr(ll int n, ll int r) {
	if (n < r) return 0LL;
	if (n == r) return 1LL;
	if (r == 2) return n * (n - 1) / 2;
	if (r == 3) return n * (n - 1) * (n - 2) / 6;
}


void solve() {
	int n, x; cin >> n;
	map<int, int> mp;
	set<int> s;
	fori(0, n) cin >> x, mp[x]++, s.insert(x);

	ll int answer = 0;

	for (auto k : s) {
		int x = k;
		ll int x_freq = mp[k];

		int y = x + 1;
		ll int y_freq = mp[y];

		int z = x + 2;
		ll int z_freq = mp[z];

		// cout << x_freq << " " << y_freq << " " << z_freq; NL

		answer += (
		              (x_freq * y_freq * z_freq) + 		// 1,2,3
		              (									// 1,2
		                  x_freq * ncr(y_freq, 2) + 	////// (1 from '1' && 2 from '2')
		                  ncr(x_freq, 2) * y_freq		////// (2 from '1' && 1 from '2')
		              ) +
		              (													// 1,3
		                  x_freq * ncr(z_freq, 2) + 	////// (1 from '1' && 2 from '3')
		                  ncr(x_freq, 2) * z_freq		////// (2 from '1' && 1 from '3')
		              ) +
		              ( ncr(x_freq, 3) )				// 3 from '1'
		          );
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