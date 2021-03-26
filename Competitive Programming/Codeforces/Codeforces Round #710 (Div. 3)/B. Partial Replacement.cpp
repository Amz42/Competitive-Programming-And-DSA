// Question: https://codeforces.com/contest/1506/problem/B
// Solution: https://codeforces.com/contest/1506/submission/111149371

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

	int start = 0, end = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == '*') {
			s[i] = 'X';
			start = i;
			break;
		}
	for (int i = n - 1; i >= 0; i--)
		if (s[i] == '*') {
			s[i] = 'X';
			end = i;
			break;
		}

	int last = 0, diff = 0;
	for (int i = start; i < end; i++) {
		if (s[i] == '*') last = i;
		if (diff == k) {
			s[last] = 'X';
			diff = i - last;
		}
		diff++;
	}

	int answer = 0;
	for (auto k : s) if (k == 'X') answer++;
	cout << answer; NL;
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