// Question: https://www.spoj.com/problems/BVAAN/
// Solution: https://www.spoj.com/status/ns=27670492


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



string a, b;
int n;
int dp[101][101][101];

int fun(int i, int j, int l) {
	if (l == 0) return 0;
	if (i == 0 || j == 0) return INT_MIN;
	if (dp[i][j][l] != -1) return dp[i][j][l];

	int answer = 0;
	if (a[i - 1] == b[j - 1])
		answer = max(fun(i - 1, j - 1, l), fun(i - 1, j - 1, l - 1) + (int)a[i - 1]);
	else
		answer = max(fun(i - 1, j, l), fun(i, j - 1, l));
	return dp[i][j][l] = answer;
}

void solve() {
	cin >> a >> b >> n;
	memset(dp, -1, sizeof dp);
	int answer = max(0, fun(a.size(), b.size(), n));
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