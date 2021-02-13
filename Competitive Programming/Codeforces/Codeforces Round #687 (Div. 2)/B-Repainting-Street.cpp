// Question: https://codeforces.com/contest/1457/problem/B
// Solution: https://codeforces.com/contest/1457/submission/99855555

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



ll int dist(int a, int b, int c, int d) {
	return abs(a - c) + abs(b - d);
}


void solve() {
	ll int n, k; cin >> n >> k;
	vector<int> v(n);
	map<int, int> mp;

	int e, mx = 0;

	for (int i = 0; i < n; i++) {
		cin >> v[i], mp[v[i]]++;
	}

	int answer = INT_MAX;

	for (int j = 1; j <= 100; j++) {
		stack<int> s;
		int ans = 0;
		int e = j;
		for (int i = 0; i < n; i++) {
			if (s.size() == 0 && v[i] == e) continue;
			s.push(v[i]);

			if (s.size() == k) {
				ans++;
				while (!s.empty()) s.pop();
			}
		}

		if (s.size()) ans++;

		answer = min(ans, answer);
	}

	cout << answer ;
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