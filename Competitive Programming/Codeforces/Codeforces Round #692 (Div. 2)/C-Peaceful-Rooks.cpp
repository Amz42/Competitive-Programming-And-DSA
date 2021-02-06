// Question: https://codeforces.com/contest/1465/problem/C
// Solution: https://codeforces.com/contest/1465/submission/101918600

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
	int n, m, x, y; cin >> n >> m;
	int row[n + 1] = {0};
	vector<int>	rooks;

	fori(0, m) {
		cin >> x >> y;
		row[x] = y;
		if (x != y) rooks.push_back(x); // rook is not on main diagonal
	}

	int visited[n + 1] = {0}, cycle = 0;
	fori(0, rooks.size()) {
		if (visited[rooks[i]]) continue;
		int current = rooks[i]; // rook from i-th row
		while (true) {
			visited[current] = i + 1; // marking current rook as visited
			current = row[current]; // looking out for empty spot on main diagonal
			if (visited[current] == i + 1) { // cycle exists
				cycle++; break;
			} else if (visited[current]) break; // some other rook may have moved from here but no clash is there
			if (row[current] == 0) break; // empty spot found on main diagonal
		}
	}

	cout << rooks.size() + cycle; NL
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