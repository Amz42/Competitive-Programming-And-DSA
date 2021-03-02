// Question: https://codeforces.com/contest/1427/problem/C
// Solution: https://codeforces.com/contest/1427/submission/102116677

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



bool reachable(int x1, int y1, int t1, int x2, int y2, int t2) {
	// if time required to cover distance > available time
	if ( abs(x1 - x2) + abs(y1 - y2) > abs(t1 - t2) ) return false;
	return true;
}


void solve() {
	int r, n; cin >> r >> n;
	vector<int> dp(n + 1, 0), tim(n + 1), x(n + 1), y(n + 1);

	int answer = 0;

	fori(0, n) {
		cin >> tim[i] >> x[i] >> y[i];

		// if current celeb is not reachable from start, it can't be reached by any other way
		if (!reachable(1, 1, 0, x[i], y[i], tim[i])) continue;

		int j = i - 1;
		int max_prevoius_celebs = 0;
		// if time difference is greater than 2*r then its obviously possible to reach i-th from j-th celebrity
		while (j >= 0 && j >= i - 4 * r) {
			if (!reachable(x[i], y[i], tim[i], x[j], y[j], tim[j])) {
				j--;
				continue;
			}

			// maximize the number of celebs reachable
			max_prevoius_celebs = max( max_prevoius_celebs, dp[j] );
			j--;
		}

		// max previous celebs reachable + current celeb
		dp[i] = max_prevoius_celebs + 1;
		answer = max(answer, dp[i]);
	}

	cout << answer; NL
	return;
}


// HINT: "It's a slightly twisted version of Longest Increasing Subsequence(LIS) Problem..."
// LOGIC: "Just check what is max number of previous celebs reachable if current celeb is selected..."



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