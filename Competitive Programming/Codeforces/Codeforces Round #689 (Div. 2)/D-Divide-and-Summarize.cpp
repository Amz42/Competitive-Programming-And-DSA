// Question: https://codeforces.com/contest/1461/problem/D
// Solution: https://codeforces.com/contest/1461/submission/100992625

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



set<ll int> answer;

void find_all_sums(vector<ll int> &v) {
	ll int sum = 0, mx = 0, mn = INT_MAX;
	fori(0, v.size()) {
		sum += v[i];
		mn = min(mn, v[i]);
		mx = max(mx, v[i]);
	}

	answer.insert(sum);

	if (mn == mx || v.size() == 0) return;

	ll int mid = (mn + mx) / 2;
	vector<ll int> a, b;
	for (auto k : v) {
		if (k > mid) b.push_back(k);
		else a.push_back(k);
	}

	find_all_sums(a);
	find_all_sums(b);
}

void solve() {
	int n, q; cin >> n >> q;
	vector<ll int> a(n); fori(0, n) cin >> a[i];

	answer.clear();
	find_all_sums(a);

	while (q-- > 0) {
		ll int x; cin >> x;

		if (answer.count(x)) cout << "Yes";
		else cout << "No";
		NL
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