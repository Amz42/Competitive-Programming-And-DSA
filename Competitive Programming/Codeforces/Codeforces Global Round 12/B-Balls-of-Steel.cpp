// Question: https://codeforces.com/contest/1450/problem/B
// Solution: https://codeforces.com/contest/1450/submission/100540843

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



ll int dist(ll int x1, ll int y1, ll int x2, ll int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}


void solve() {
	ll int n, k; cin >> n >> k;
	pair<ll int , ll int> a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}


	for (int i = 0; i < n; i++) {
		bool yes = true;
		for (int j = 0; j < n; j++) {
			if (dist(a[i].first, a[i].second, a[j].first, a[j].second) > k) {
				yes = false;
				break;
			}
		}

		if (yes) {
			cout << "1"; NL
			return;
		}
	}

	cout << "-1"; NL
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