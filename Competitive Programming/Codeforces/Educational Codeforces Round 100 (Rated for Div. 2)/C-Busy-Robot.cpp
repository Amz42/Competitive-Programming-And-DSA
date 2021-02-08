// Question: https://codeforces.com/contest/1463/problem/C
// Solution: https://codeforces.com/contest/1463/submission/101802654

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
	ll int t[n + 1], x[n], pos[n + 1];
	fori(0, n) cin >> t[i] >> x[i];
	t[n] = LLONG_MAX;

	ll int destination = 0, busy_till = 0;
	fori(0, n) {
		if (busy_till <= t[i]) {
			// command will be executed
			pos[i] = destination;
			busy_till = t[i] + abs(x[i] - destination);
			destination = x[i];
		} else {
			// command will not be executed
			pos[i] = destination + (busy_till - t[i]) * (pos[i - 1] > destination ? +1 : -1);
		}
	}

	pos[n] = destination;

	int answer = 0;
	fori(0, n) {
		if (
		    (pos[i] <= x[i] && x[i] <= pos[i + 1]) ||
		    (pos[i + 1] <= x[i] && x[i] <= pos[i])
		)answer++;
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