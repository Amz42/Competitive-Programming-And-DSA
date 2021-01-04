// Question: https://codeforces.com/contest/1043/problem/C
// Solution: https://codeforces.com/problemset/submission/1043/103174918

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
	string s; cin >> s;
	int n = s.size();
	bool v[n] = {0};
	int i = 0;

	while (i < n) {
		int b = 0, a = 0, lastb, lasta;
		while (i < n && s[i] == 'b') b++, lastb = i++;
		while (i < n && s[i] == 'a') a++, lasta = i++;
		if (a && b) v[lastb] = v[lasta] = 1;
	}

	for (auto k : v) cout << (k ? "1 " : "0 ");
}


// APPROACH:
// String will obviously be sorted at the end.. You can try by checking
// Now, Only thing left is to check how & where to invert
// Let say if 'b' appears continuously then optimal inversion will be at last 'b' only when
// there is some 'a' available after all 'b's...
// One Edge case:
//      if only 'a' appears then there is no need of inversion obviously

// So, just check the last occurence of 'b' & then 'a' & invert prefix string at that index...



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