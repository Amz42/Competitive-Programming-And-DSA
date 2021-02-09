// Question: https://codeforces.com/contest/1450/problem/C1
// Solution: https://codeforces.com/contest/1450/submission/100586200

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
	char mat[n][n]; int rgb[3] = {0};

	fori(0, n) forj(0, n) {
		cin >> mat[i][j];
		if (mat[i][j] == 'X') rgb[(i + j) % 3]++;
	}

	int ideal = 0;
	int freq = INT_MAX;
	for (int i = 0; i < 3; i++) {
		if (rgb[i] < freq) freq = rgb[i], ideal = i;
	}


	fori(0, n) {
		forj(0, n) {
			if ((i + j) % 3 == ideal && mat[i][j] == 'X') mat[i][j] = 'O';
			cout << mat[i][j];
		}
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