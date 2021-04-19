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






void solve(int tc) {
	int n; cin >> n;
	vector<ll int> v(n, 0);
	for (int i = 0; i < n; i++) cin >> v[i];

	vector<ll> diff_pref(n, LLONG_MAX); // diff_pref[i] = v[i] - v[i-1]
	vector<ll> diff_suff(n, LLONG_MAX); // diff_suff[i] = v[i+1] - v[i]

	for (int i = 1; i < n; i++)
		diff_pref[i] = v[i] - v[i - 1];

	for (int i = n - 2; i >= 0; i--)
		diff_suff[i] = v[i + 1] - v[i];

	vector<ll int> pref(n, 2);
	vector<ll int> suff(n, 2);

	pref[0] = suff[n - 1] = 1;

	// calculate length of longest arithmetic subarray ending
	// at every index in prefix manner
	for (int i = 2; i < n; i++) {
		if (diff_pref[i] == diff_pref[i - 1])
			pref[i] = 1 + pref[i - 1];
	}

	// calculate length of longest arithmetic subarray ending
	// at every index in suffix manner
	for (int i = n - 3; i >= 0; i--) {
		if (diff_suff[i] == diff_suff[i + 1])
			suff[i] = 1 + suff[i + 1];
	}

	// changing first element or last element
	ll int ans = max(1 + suff[1], 1 + pref[n - 2]);

	// maximize answer now by changing a single element

	for (ll i = 1; i < n - 1; i++) {
		// answer for subarray ending at current index
		// without changing any element
		ans = max(ans, 1 + suff[i + 1]);
		ans = max(ans, 1 + pref[i - 1]);

		// check if current element can be changed or not?

		if ((v[i + 1] - v[i - 1]) & 1) continue;

		ll int diff = (v[i + 1] - v[i - 1]) / 2;

		if (i < 2 or diff_pref[i - 1] == diff)
			ans = max(ans, 2 + pref[i - 1]);

		if (i > n - 3 or diff_suff[i + 1] == diff)
			ans = max(ans, 2 + suff[i + 1]);

		if ((i > 1 and diff_pref[i - 1] != diff) or (i < n - 2 and diff_suff[i + 1] != diff))
			continue;

		ans = max(ans, 1 + pref[i - 1] + suff[i + 1]);
	}

	cout << "Case #" << tc << ": " << ans; NL
}






int main() {
	optimize
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	long long int tests = 1;

	cin >> tests;

	for (ll int test_case = 1; test_case <= tests; test_case++) {
		solve(test_case);
	}

	// cerr << "Execution Time : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}