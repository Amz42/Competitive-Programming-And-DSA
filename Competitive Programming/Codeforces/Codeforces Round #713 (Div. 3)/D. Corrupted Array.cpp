// Question: https://codeforces.com/contest/1512/problem/D
// Solution: https://codeforces.com/contest/1512/submission/112626634

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
	ll int n, sum = 0; cin >> n;
	vector<ll int> v(n + 2);
	multiset<ll int> ms;
	for (int i = 0; i < n + 2; i++) cin >> v[i], ms.insert(v[i]), sum += v[i];
	sort(v.rbegin(), v.rend());

	auto k = ms;
	if (k.find(v[0]) != k.end()) {
		k.erase(k.find(v[0]));
		if (k.find(sum - 2 * v[0]) != k.end()) {
			k.erase(k.find(sum - 2 * v[0]));

			for (auto g : k) cout << g << " "; NL
			return;
		}
	}

	k = ms;
	if (k.find(v[1]) != k.end()) {
		k.erase(k.find(v[1]));
		if (k.find(sum - 2 * v[1]) != k.end()) {
			k.erase(k.find(sum - 2 * v[1]));

			for (auto g : k) cout << g << " "; NL
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