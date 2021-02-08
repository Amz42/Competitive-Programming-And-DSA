// Question: https://codeforces.com/contest/1461/problem/B
// Solution: https://codeforces.com/contest/1461/submission/100966375

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
	int n, m; cin >> n >> m;
	char s[n][m];
	int left[n][m], right[n][m];

	// input matrix
	fori(0, n) forj(0, m) cin >> s[i][j], left[i][j] = right[i][j] = 0;

	fori(0, n) {
		forj(0, m) {
			if (s[i][j] == '*') left[i][j]++;
			if (j && s[i][j] == '*') left[i][j] += left[i][j - 1];
		}
		for (int j = m - 1; j >= 0; j--) {
			if (s[i][j] == '*') right[i][j]++;
			if (j + 1 < m && s[i][j] == '*') right[i][j] += right[i][j + 1];
		}
	}


	ll int answer = 0;

	fori(0, n) {
		forj(0, m) {
			if (s[i][j] == '*') {
				int level = 0;
				for (int k = i; k < n; k++, level++) {
					if (
					    j - level >= 0 and
					    j + level < m and
					    right[k][j - level] > (level * 2) and
					    left[k][j + level] > (level * 2)
					) answer++;
					else break;
				}
			}
		}
	}


	cout << answer;
	NL
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