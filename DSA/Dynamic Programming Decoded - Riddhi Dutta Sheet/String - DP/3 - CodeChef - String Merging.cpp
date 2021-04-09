// Question: https://www.codechef.com/problems/STRMRG
// Solution: https://www.codechef.com/viewsolution/44829402

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


int LCS(string a, string b, int n, int m) {
	int dp[n + 1][m + 1];

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 or j == 0) {
				dp[i][j] = 0;
				continue;
			}

			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

			if (a[i - 1] == b[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
		}
	}
	return dp[n][m];
}

void solve() {
	int n, m; cin >> n >> m;
	string a, b; cin >> a >> b;

	string A = "";
	for (int i = 0; i < n - 1; i++)
		if (a[i] != a[i + 1]) A += a[i];
	A += a[n - 1];

	string B = "";
	for (int i = 0; i < m - 1; i++)
		if (b[i] != b[i + 1]) B += b[i];
	B += b[m - 1];

	cout << A.length() + B.length() - LCS(A, B, A.size(), B.size()); NL
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