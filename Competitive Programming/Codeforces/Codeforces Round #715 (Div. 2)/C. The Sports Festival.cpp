// Question: https://codeforces.com/contest/1509/problem/C
// Solution: https://codeforces.com/contest/1509/submission/113262377

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


ll int dp[2001][2001];
vector<ll int> v;

ll int fun(int l, int r) {
	if (l >= r) return 0;
	if (dp[l][r] != -1) return dp[l][r];
	return dp[l][r] = min(fun(l + 1, r), fun(l, r - 1)) + v[r] - v[l];
}

void solve() {
	memset(dp , -1, sizeof dp);
	ll int n, x; cin >> n;
	for (int i = 0; i < n; i++) cin >> x, v.push_back(x);
	sort(v.begin(), v.end());
	cout << fun(0, n - 1);
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