// Question: https://codeforces.com/contest/1499/problem/C
// Solution: https://codeforces.com/contest/1499/submission/110371723

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
	ll int n; cin >> n;
	ll int v[n];
	for (int i = 0; i < n; i++) cin >> v[i];

	set<int> s1, s2;
	ll int answer = n * (v[0] + v[1]);
	ll int sum1 = v[0], sum2 = v[1];

	int x = 1, y = 1;
	s1.insert(v[0]);
	s2.insert(v[1]);

	for (int i = 2; i < n; i++) {
		if (i & 1) {
			sum2 += v[i];
			s2.insert(v[i]);
			int mn1 = *s1.begin();
			int mn2 = *s2.begin();
			answer = min(
			             answer,
			             sum1 - mn1 + (n - (x - 1)) * mn1 +
			             sum2 - mn2 + (n - y) * mn2
			         );
			y++;
		} else {
			sum1 += v[i];
			s1.insert(v[i]);
			int mn1 = *s1.begin();
			int mn2 = *s2.begin();
			answer = min(
			             answer,
			             sum1 - mn1 + (n - x) * mn1 +
			             sum2 - mn2 + (n - (y - 1)) * mn2
			         );
			x++;
		}
	}

	cout << answer; NL
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