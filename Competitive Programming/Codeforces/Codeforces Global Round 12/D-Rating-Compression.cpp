// Question: https://codeforces.com/contest/1450/problem/D
// Solution: https://codeforces.com/contest/1450/submission/101235103

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
	map<int, int> mp;
	int a[n]; fori(0, n) cin >> a[i], mp[a[i]]++;

	string answer = "";
	int l = 0, r = n - 1;
	bool zero = false;

	fori(0, n) {
		if (zero) answer += '0';
		else if (mp[i + 1] == 0) answer += '0', zero = true;
		else {
			if (a[l] == i + 1 && mp[i + 1] == 1) l++;
			else if (a[r] == i + 1 && mp[i + 1] == 1) r--;
			else zero = true;
			answer += '1';
		}
	}

	sort(a, a + n);

	zero = false;
	fori(0, n) if (a[i] != i + 1) { zero = true; break; }

	if (!zero) answer[n - 1] = '1';

	fori(0, n) cout << answer[n - i - 1];
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