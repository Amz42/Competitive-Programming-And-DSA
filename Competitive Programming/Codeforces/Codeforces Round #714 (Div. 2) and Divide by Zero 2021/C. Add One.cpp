// Question: https://codeforces.com/contest/1513/problem/C
// Solution: https://codeforces.com/contest/1513/submission/112700449

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


ll int dp[11][2 * 100000 + 5];

ll int fun(int digit, int m) {
	if (dp[digit][m] != -1) return dp[digit][m];
	if (digit + m < 10) return dp[digit][m] = 1;
	return dp[digit][m] = (
	                          fun(1, m - (10 - digit)) % MOD +
	                          fun(0, m - (10 - digit)) % MOD
	                      ) % MOD;
}

void precomp() {
	memset(dp, -1, sizeof dp);

	for (int i = 0; i < 10; i++) {
		for (int j = 2 * 1e5 + 1; j >= 0; j--) {
			fun(i, j);
		}
	}
}


void solve() {
	ll int n, m; cin >> n >> m;

	ll int answer = 0;
	while (n) {
		answer = (
		             answer +
		             (fun(n % 10, m) % MOD)
		         ) % MOD;
		n /= 10;
	}

	cout << (ll int)answer; NL
	return;
}






int main() {
	optimize
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	long long int tests = 1;

	precomp();

	cin >> tests;

	for (ll int test_case = 1; test_case <= tests; test_case++) {
		solve();
	}

	cerr << "Execution Time : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}