// Question: https://www.spoj.com/problems/CPCRC1C/
// Solution: https://www.spoj.com/status/ns=27656518

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



int n;
int digit[12];
ll int dp[12][100][2];

ll int fun(int pos, int sum, bool restricted) {
	if (pos > n) return sum;
	if (dp[pos][sum][restricted] != -1)
		return dp[pos][sum][restricted];

	int limit = restricted ? digit[pos] : 9;
	ll int answer = 0;
	for (int i = 0; i <= limit; i++)
		answer += fun(pos + 1, sum + i, (restricted && i == limit) );

	return dp[pos][sum][restricted] = answer;
}

ll int SumOfDigits(string s) {
	ll int answer = 0;
	for (auto k : s) answer += k - '0';
	return answer;
}

void solve() {
	while (true) {
		string a, b; cin >> a >> b;
		if (a == "-1") break;

		memset(dp, -1, sizeof dp);
		for (int i = 0; i < a.size(); i++)
			digit[i + 1] = a[i] - '0';
		n = a.size();
		ll int L = fun(1, 0, true);

		memset(dp, -1, sizeof dp);
		for (int i = 0; i < b.size(); i++)
			digit[i + 1] = b[i] - '0';
		n = b.size();
		ll int R = fun(1, 0, true);

		cout << R - L + SumOfDigits(a); NL
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