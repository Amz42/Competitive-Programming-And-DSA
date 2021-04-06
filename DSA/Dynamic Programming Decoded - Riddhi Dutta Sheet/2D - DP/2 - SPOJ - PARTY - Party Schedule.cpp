// Question: https://www.spoj.com/problems/PARTY/
// Solution: https://www.spoj.com/status/ns=27662011#

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
	while (true) {
		int budget, n; cin >> budget >> n;
		if (budget == 0 && n == 0) break;

		int cost[n], joy[n];
		for (int i = 0; i < n; i++) cin >> cost[i] >> joy[i];

		int dp[n + 1][budget + 1][2];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= budget; j++) {
				// (no party available) or (budget is 0) then enjoy = 0
				if (i == 0 || j == 0) {
					// cost & enjoy
					dp[i][j][0] = dp[i][j][1] = 0;
					continue;
				}

				dp[i][j][0] = dp[i - 1][j][0];
				dp[i][j][1] = dp[i - 1][j][1];

				// this party can be visited
				if (j >= cost[i - 1]) {
					// joy is more if we take this party
					if (dp[i - 1][j][0] < dp[i - 1][j - cost[i - 1]][0] + joy[i - 1]) {
						dp[i][j][0] = dp[i - 1][j - cost[i - 1]][0] + joy[i - 1]; // joy
						dp[i][j][1] = dp[i - 1][j - cost[i - 1]][1] + cost[i - 1]; // cost
					}
					// joy is same if we take this party but cost is less
					else if (
					    (dp[i - 1][j][0] == dp[i - 1][j - cost[i - 1]][0] + joy[i - 1]) &&
					    (dp[i - 1][j][1] > dp[i - 1][j - cost[i - 1]][1] + cost[i - 1])
					) {
						dp[i][j][0] = dp[i - 1][j - cost[i - 1]][0] + joy[i - 1]; // joy
						dp[i][j][1] = dp[i - 1][j - cost[i - 1]][1] + cost[i - 1]; // cost
					}
				}
			}
		}

		cout << dp[n][budget][1] << " " << dp[n][budget][0]; NL
	}
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