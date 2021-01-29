// Question: https://codeforces.com/contest/1476/problem/D
// Solution: https://codeforces.com/contest/1476/submission/105933726

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
	int cities = n + 1;
	string s; cin >> s;

	int l1[n], l2[n], r1[n], r2[n];

	int last1, last2; last1 = last2 = -1;
	fori(0, n) {
		// type1
		if (
		    (i % 2 == 0 && s[i] == 'L') ||
		    (i % 2 == 1 && s[i] == 'R')
		) last1 = i;

		// type2
		if (
		    (i % 2 == 0 && s[i] == 'R') ||
		    (i % 2 == 1 && s[i] == 'L')
		) last2 = i;

		l1[i] = last1;
		l2[i] = last2;
	}

	last1 = last2 = n;
	for (int i = n - 1; i >= 0; i--) {
		// type1
		if (
		    (i % 2 == 0 && s[i] == 'L') ||
		    (i % 2 == 1 && s[i] == 'R')
		) last1 = i;

		// type2
		if (
		    (i % 2 == 0 && s[i] == 'R') ||
		    (i % 2 == 1 && s[i] == 'L')
		) last2 = i;

		r1[i] = last1;
		r2[i] = last2;
	}

	// cout << "L1:";
	// fori(0, n) cout << l1[i] << " "; NL
	// cout << "R1:";
	// fori(0, n) cout << r1[i] << " "; NL
	// cout << "L2:";
	// fori(0, n) cout << l2[i] << " "; NL
	// cout << "R2:";
	// fori(0, n) cout << r2[i] << " "; NL
	// return;

	vector<int> answer(n + 1, 0);
	fori(0, n + 1) {
		int left = 0, right = 0;

		if (i < n) right = (i & 1 ? r2[i] : r1[i]) - i;
		if (i) left = i - 1 - (i & 1 ? l2[i - 1] : l1[i - 1]);

		answer[i] = left + right + 1;
	}

	for (auto k : answer) cout << k << " "; NL
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