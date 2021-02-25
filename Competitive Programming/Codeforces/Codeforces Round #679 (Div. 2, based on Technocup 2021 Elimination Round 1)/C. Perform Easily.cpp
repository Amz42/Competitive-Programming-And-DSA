// Question: https://codeforces.com/contest/1435/problem/C
// Solution: https://codeforces.com/contest/1435/submission/101219289

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
	ll int a[6]; for (auto &i : a) cin >> i;
	ll int n, x, answer = LLONG_MAX; cin >> n;
	vector<pair<ll int, ll int>> v;

	fori(0, n) {
		cin >> x;
		forj(0, 6) { // play i-th note on all 6 frets
			v.push_back(make_pair(x - a[j], i));
		}
	}

	sort(v.begin(), v.end());
	map<ll int, ll int> mp;

	int ptr = 0;
	fori(0, v.size()) {
		mp[v[i].second]++;

		while (mp.size() == n) {
			answer = min(answer, v[i].first - v[ptr].first ); // finding distance between points
			mp[v[ptr].second]--;
			if (mp[v[ptr].second] == 0) mp.erase(v[ptr].second);
			ptr++;
		}
	}

	cout << answer;
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