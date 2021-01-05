// Question: https://codeforces.com/contest/1471/problem/B
// Solution: https://codeforces.com/contest/1471/submission/103465390

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
	ll int N, robot, e; cin >> N >> robot;
	queue<pair<ll int, ll int>> q;
	for (int i = 0; i < N; i++) cin >> e, q.push({e, 1});

	ll int ans = 0;
	while (!q.empty()) {
		auto g = q.front(); q.pop();
		ans += (g.first * g.second);
		if (g.first % robot) {break;}
		q.push({g.first / robot, g.second * robot});
	}

	while (!q.empty()) {
		auto g = q.front(); q.pop();
		ans += (g.first * g.second);
	}

	cout << ans << "\n";
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