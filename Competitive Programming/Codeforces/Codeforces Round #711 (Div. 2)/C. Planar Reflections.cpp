// Question: https://codeforces.com/contest/1498/problem/C
// Solution: https://codeforces.com/contest/1498/submission/111412656

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




ll int n, k;
ll int dp[1005][1005][2];

int fun(int mirror, int intensity, bool direction) {
	if (intensity == 1) return 1;
	if (dp[mirror][intensity][direction] != -1)
		return dp[mirror][intensity][direction];

	int answer = 2; // counting myself & my descendent particle

	// I was moving towards right
	if (direction) {
		// I keep moving towards right
		if (mirror < n)
			answer += fun(mirror + 1, intensity, direction) - 1;

		answer %= MOD;

		// My descendent moves left with (intensity-1)
		if (mirror > 1)
			answer += fun(mirror - 1, intensity - 1, !direction) - 1;
	}
	// I was moving towards left
	else {
		// I keep moving towards left
		if (mirror > 1)
			answer += fun(mirror - 1, intensity, direction) - 1;

		answer %= MOD;

		// My descendent moves right with (intensity-1)
		if (mirror < n)
			answer += fun(mirror + 1, intensity - 1, !direction) - 1;
	}

	answer %= MOD;
	return dp[mirror][intensity][direction] = answer;
}

void solve() {
	cin >> n >> k;
	memset(dp , -1, sizeof dp);

	cout << fun(1, k, 1); NL
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