// Question: https://www.codechef.com/problems/DBOY
// Solution: https://www.codechef.com/viewsolution/44653164

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
	int n; cin >> n;
	int dist[n]; for (int i = 0; i < n; i++) cin >> dist[i];
	int petrol[n]; for (int i = 0; i < n; i++) cin >> petrol[i];

	int dp[1001]; memset(dp, -1, sizeof dp); dp[0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = petrol[i]; j < 1001; j++) {
			if (
			    (dp[j - petrol[i]] != -1) &&
			    (dp[j] == -1 || dp[j] > dp[j - petrol[i]] + 1)
			) dp[j] = dp[j - petrol[i]] + 1;
		}
	}

	int answer = 0;
	for (int i = 0; i < n; i++) answer += dp[2 * dist[i]];
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