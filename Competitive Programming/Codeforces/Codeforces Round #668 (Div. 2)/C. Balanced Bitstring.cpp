// Question: https://codeforces.com/contest/1405/problem/C
// Solution: https://codeforces.com/contest/1405/submission/102087297

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
	int n, k; cin >> n >> k;
	string s; cin >> s;

	bool yes = true;
	int zeros = 0, ones = 0;
	fori(0, k) {
		char current = s[i];
		for (int j = i; j < n; j += k) {
			if (
			    (s[j] == '0' && current == '1') ||
			    (s[j] == '1' && current == '0')
			) { yes = false; break; }
			else {
				if (s[j] != '?') current = s[j];
			}
		}
		if (current == '1') ones++;
		if (current == '0') zeros++;
	}

	if ( (ones > k / 2) || (zeros > k / 2) || !yes) cout << "NO";
	else cout << "YES";
	NL
	return;
}

// LOGIC: " next k-th character should be same or '?' "
// EXPLAINATION:
// because when current character is removed,
// then same should enter from end of the string to compensate its presence in beginning



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