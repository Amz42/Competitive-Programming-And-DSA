// Question: https://codeforces.com/contest/1501/problem/C
// Solution: https://codeforces.com/contest/1501/submission/109899786

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





vector<pair<int, int>> p(1e7 + 1, make_pair(-1, -1));
void solve() {
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int s = a[i] + a[j];
			if (
			    p[s].first != -1 &&
			    i != p[s].first &&
			    i != p[s].second &&
			    j != p[s].first &&
			    j != p[s].second
			) {
				cout << "YES"; NL
				cout << p[s].first + 1 << " ";
				cout << p[s].second + 1 << " ";
				cout << i + 1 << " ";
				cout << j + 1;
				return;
			}
			p[s] = make_pair(i, j);
		}
	}

	cout << "NO";
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