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



ll int fun(ll int x, ll int y) {
	return max(min(x, y / 2) - 1, 0LL);
}


void solve(int tc) {
	int n, m; cin >> n >> m;

	int mat[n][m];
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> mat[i][j];

	int up[n][m], down[n][m], left[n][m], right[n][m];


	for (int i = 0; i < n; i++) {
		// left to right
		for (int j = 0; j < m; j++) {
			left[i][j] = mat[i][j];
			if (mat[i][j] == 0) continue;
			if (j > 0) left[i][j] += left[i][j - 1];
		}

		// right to left
		for (int j = m - 1; j >= 0; j--) {
			right[i][j] = mat[i][j];
			if (mat[i][j] == 0) continue;
			if (j < m - 1) right[i][j] += right[i][j + 1];
		}
	}

	for (int j = 0; j < m; j++) {
		// up to down
		for (int i = 0; i < n; i++) {
			up[i][j] = mat[i][j];
			if (mat[i][j] == 0) continue;
			if (i > 0) up[i][j] += up[i - 1][j];
		}

		// down to up
		for (int i = n - 1; i >= 0; i--) {
			down[i][j] = mat[i][j];
			if (mat[i][j] == 0) continue;
			if (i < n - 1) down[i][j] += down[i + 1][j];
		}
	}

	ll int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			answer += (
			              fun(up[i][j], left[i][j]) +
			              fun(left[i][j], up[i][j]) +
			              fun(up[i][j], right[i][j]) +
			              fun(right[i][j], up[i][j]) +
			              fun(down[i][j], left[i][j]) +
			              fun(left[i][j], down[i][j]) +
			              fun(down[i][j], right[i][j]) +
			              fun(right[i][j], down[i][j])
			          );
		}
	}

	// for (int i = 0; i < n; i++) {for (int j = 0; j < m; j++) cout << up[i][j] << " ";  NL}; NL
	// for (int i = 0; i < n; i++) {for (int j = 0; j < m; j++) cout << down[i][j] << " ";  NL}; NL
	// for (int i = 0; i < n; i++) {for (int j = 0; j < m; j++) cout << left[i][j] << " ";  NL}; NL
	// for (int i = 0; i < n; i++) {for (int j = 0; j < m; j++) cout << right[i][j] << " ";  NL}; NL

	cout << "Case #" << tc << ": " << answer; NL
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
		solve(test_case);
	}

	cerr << "Execution Time : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}