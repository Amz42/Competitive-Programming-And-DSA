// Question: https://www.codechef.com/problems/FROGV
// Solution: https://www.codechef.com/viewsolution/44705555

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
	int n, k, p; cin >> n >> k >> p;

	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) cin >> v[i].first, v[i].second = i + 1;
	sort(v.begin(), v.end());

	int dsu[n + 1];
	int dsu_no = 0;

	dsu[v[0].second] = dsu_no;
	for (int i = 1; i < n; i++) {
		if (v[i].first - v[i - 1].first > k)
			dsu_no++;
		dsu[v[i].second] = dsu_no;
	}

	while (p--) {
		int a, b; cin >> a >> b;
		cout << (dsu[a] == dsu[b] ? "Yes" : "No"); NL
	}

	return;
}






int main() {
	optimize
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	long long int tests = 1;

	// cin >> tests;

	for (ll int test_case = 1; test_case <= tests; test_case++) {
		solve();
	}

	cerr << "Execution Time : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}