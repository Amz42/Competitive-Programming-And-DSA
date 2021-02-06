// Question: https://codeforces.com/contest/1459/problem/C
// Solution: https://codeforces.com/contest/1459/submission/101792859

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
	ll int n, m, x; cin >> n >> m;
	ll int first;

	if (n == 1) {
		cin >> first;
		fori(0, m) cin >> x, cout << first + x << " ";
		return;
	}

	ll int b[m];

	vector<ll int> v;
	cin >> first;
	fori(0, n - 1) cin >> x, v.push_back(abs(first - x));

	ll int g = v[0];
	fori(1, v.size()) g = __gcd(g, v[i]);

	fori(0, m) {
		cin >> x;
		cout << __gcd( first + x , g) << " ";
	}
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