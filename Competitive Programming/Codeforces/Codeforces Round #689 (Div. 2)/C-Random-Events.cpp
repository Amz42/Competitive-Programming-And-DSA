// Question: https://codeforces.com/contest/1461/problem/C
// Solution: https://codeforces.com/contest/1461/submission/100988918

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
	int n, m; cin >> n >> m;
	int a[n + 1]; fori(0, n) cin >> a[i + 1];

	vector<pair<int , double>> v(m);
	fori(0, m) cin >> v[i].first >> v[i].second;

	int index = -1;
	fori(0, n) if (a[i + 1] != i + 1) index = i + 1;

	if (index == -1) {
		cout << "1.000000"; NL
		return;
	}

	double answer = 1.0;

	for (auto k : v) {
		if (k.first >= index) {
			answer *= (1.0 - k.second);
		}
	}

	cout << fixed << setprecision(12);
	cout << 1.0 - answer; NL
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