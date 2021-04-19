// Question: https://codeforces.com/contest/1514/problem/C
// Solution: https://codeforces.com/contest/1514/submission/113556472

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

	bool used[n] = {0};
	ll int prod = 1, c = 0;

	for (int i = 1; i < n; i++) {
		if (__gcd(n, i) == 1) {
			used[i] = 1;
			prod = (prod * i) % n;
			c++;
		}
	}

	if (prod % n != 1) used[prod % n] = 0, c--;

	cout << c; NL
	for (int i = 1; i < n; i++) if (used[i]) cout << i << " ";

	// cout << "Case #" << tc << ": " << answer; NL
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
		solve(test_case);
	}

	// cerr << "Execution Time : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}