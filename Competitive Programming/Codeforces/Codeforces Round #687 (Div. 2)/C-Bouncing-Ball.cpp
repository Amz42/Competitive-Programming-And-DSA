// Question: https://codeforces.com/contest/1457/problem/C
// Solution: https://codeforces.com/contest/1457/submission/99881931

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
	ll int n, p, k; cin >> n >> p >> k;
	string s; cin >> s;
	ll int x, y; cin >> x >> y;
	ll int prf[n] = {0};

	for (ll int i = n - 1; i > n - k - 1; i--) prf[i] = (s[i] == '0');

	for (ll int i = n - k - 1; i >= 0; i--) {
		prf[i] = prf[i + k] + (s[i] == '0');
	}

	// cout << "prf: ";
	// for (auto k : prf) cout << k << " ";
	// NL

	ll int answer = INT_MAX;
	ll int r = 0;
	for (ll int i = p - 1; i < n; i++) {
		ll int cost = r * y + prf[i] * x;
		r++;
		answer = min(answer, cost);
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