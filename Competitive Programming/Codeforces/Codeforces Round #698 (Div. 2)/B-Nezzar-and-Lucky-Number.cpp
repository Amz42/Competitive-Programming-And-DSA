// Question: https://codeforces.com/contest/1478/problem/B
// Solution: https://codeforces.com/contest/1478/submission/105756160

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
	ll int queries, d; cin >> queries >> d;

	vector<int> my_vec;
	int original_D = d;

	fori(1, 11) my_vec.pb(original_D), original_D += 10;

	bool is_valid[100] = {0};

	fori(0, my_vec.size()) {
		int k = my_vec[i];
		while (k < 100) {
			is_valid[k] = 1;
			k += d;
		}
	}

	fori(0, queries) {
		ll int number; cin >> number;
		if (number >= d * 10) cout << "YES";
		else cout << (is_valid[number] ? "YES" : "NO");
		NL
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

	cin >> tests;

	for (ll int test_case = 1; test_case <= tests; test_case++) {
		solve();
	}

	cerr << "Execution Time : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}