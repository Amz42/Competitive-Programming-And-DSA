// Question: https://codeforces.com/contest/1462/problem/F
// Solution: https://codeforces.com/contest/1462/submission/101479737

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
	ll int n, l, r; cin >> n;
	vector<ll int> seg_start, seg_end;
	vector<pair<int, int>> seg;

	fori(0, n) {
		cin >> l >> r;
		seg_start.push_back(l);
		seg_end.push_back(r);
		seg.push_back(make_pair(l, r));
	}

	sort(seg_start.begin(), seg_start.end());
	sort(seg_end.begin(), seg_end.end());

	ll int answer = LLONG_MAX;
	for (auto k : seg) {
		l = k.first, r = k.second;
		answer = min(
		             answer,
		             (ll int)(
		                 (lower_bound(all(seg_end), l) - seg_end.begin()) +
		                 (seg_start.end() - upper_bound(all(seg_start), r))
		             )
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