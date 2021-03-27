// Question: https://codeforces.com/contest/1506/problem/E
// Solution: https://codeforces.com/contest/1506/submission/111166909

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
	int n; cin >> n;
	int a[n], mn[n] = {0}, mx[n] = {0}; for (int i = 0; i < n; i++) cin >> a[i];

	set<int> s1, s2;
	for (int i = 1; i <= n; i++) s1.insert(i), s2.insert(i);


	int i = 0;
	while (i < n) {
		int e = a[i];
		mn[i] = e; s1.erase(e);
		mx[i] = e; s2.erase(e);
		i++;
		while (i < n && a[i] == e) i++;
	}

	// setting the minimum array
	for (int i = 0; i < n; i++) {
		if (!mn[i]) s1.erase(mn[i] = *s1.begin());
		cout << mn[i] << " ";
	}
	NL

	int mxx = mx[0];
	for (int i = 0; i < n; i++) {
		mxx = max(mxx, mx[i]);
		if (!mx[i]) {
			auto k = s2.lower_bound(mxx); k--;
			s2.erase(mx[i] = *k);
		}
		cout << mx[i] << " ";
	}

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