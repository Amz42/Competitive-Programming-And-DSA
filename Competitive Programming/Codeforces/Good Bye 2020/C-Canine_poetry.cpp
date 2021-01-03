// Question: https://codeforces.com/contest/1466/problem/C
// Solution: https://codeforces.com/contest/1466/submission/102836512

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
	ll int answer = 0;
	string s; cin >> s;

	int n = s.size();
	bool changed[n] = {0};
	fori(0, n) {
		if (changed[i]) {continue;}
		if (i + 2 < n) { // next two char are available
			if ((s[i] == s[i + 1] && !changed[i + 1]) && (s[i] == s[i + 2] && !changed[i + 2]) ) { // both next 2 are same
				answer += 2;
				changed[i + 1] = changed[i + 2] = 1;
			}
			if (s[i] == s[i + 2] && !changed[i + 2]) {
				answer += 1; changed[i + 2] = 1;
			}
		}
		if (i + 1 < n) {
			if (s[i] == s[i + 1] && !changed[i + 1]) {
				answer += 1; changed[i + 1] = 1;
			}
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