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
	int n, x, y; cin >> n;
	vector<pair<int, int>> v;
	fori(0, n) cin >> x >> y, v.push_back(make_pair(x, y));

	int answer = 0;
	fori(0, n) {
		forj(i + 1, n) {
			double slope = (v[j].second - v[i].second) / (double)(v[j].first - v[i].first);
			if (slope >= -1 * (1.0) and slope <= (1.0)) answer++;
		}
	}

	cout << answer;
}


/*
APPROACH:
Just use simple mathematics formula to find slope of line
passing through a pair of points.
Use mapping of points to find all possible configurations...
*/



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