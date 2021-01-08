// Question: https://codeforces.com/contest/496/problem/B
// Solution: https://codeforces.com/contest/496/submission/103718989

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



int n;
string s, answer;

int compare(string a, string b) {
	for (int i = 0; i < (int)a.size(); i++) {
		if (a[i] < b[i]) return -1;
		if (a[i] > b[i]) return +1;
	}
	return 0;
}

void check(string s) {
	string newString;
	for (int i = 0; i < n; i++) {
		newString = s.substr(i, n - i) + s.substr(0, i);
		// cout << newString; NL
		if (compare(newString, answer) < 0) answer = newString;
	}
}

void solve() {
	cin >> n >> s;
	answer = s;

	for (int i = 0; i < 10; i++) {
		check(s);
		for (int j = 0; j < n; j++) {
			if (s[j] != '9') s[j]++;
			else s[j] = '0';
		}
	}

	// cout << s << " ";
	cout << answer;
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
		solve();
	}

	cerr << "Execution Time : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}