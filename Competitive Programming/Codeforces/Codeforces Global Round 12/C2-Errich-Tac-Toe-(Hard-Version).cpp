// Question: https://codeforces.com/contest/1450/problem/C2
// Solution: https://codeforces.com/contest/1450/submission/101220671

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
	char mat[n][n], x;
	int a[3][2]; fori(0, 3) forj(0, 2) a[i][j] = 0;

	fori(0, n) {
		forj(0, n) {
			cin >> x;
			mat[i][j] = x;
			if (x == 'X') a[(i + j) % 3][0]++;
			if (x == 'O') a[(i + j) % 3][1]++;
		}
	}

	int X = 0, O = 1;
	int operations = a[0][0] + a[1][1];

	// choosing best pair of color for symbols to flip
	fori(0, 3) {
		forj(0, 3) {
			if (i != j && a[i][0] + a[j][1] < operations) {
				operations = a[i][0] + a[j][1];
				X = i, O = j;
			}
		}
	}

	fori(0, n) {
		forj(0, n) {
			if ( (i + j) % 3 == X && mat[i][j] == 'X') mat[i][j] = 'O';
			if ( (i + j) % 3 == O && mat[i][j] == 'O') mat[i][j] = 'X';
			cout << mat[i][j];
		}
		NL
	}
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