// Question: https://codeforces.com/contest/1457/problem/D
// Solution: https://codeforces.com/contest/1457/submission/99932843

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
	int n, x; cin >> n;
	int prf[n + 1] = {0};
	for (int i = 1; i <= n; i++) {
		cin >> x;
		prf[i] = x ^ prf[i - 1];
	}

	if (n > 58) {
		cout << "1";
		return;
	}

	int answer = INT_MAX;

	for (int i = 0; i < n - 1; i++) { // START POSITION
		for (int j = i + 1; j < n; j++) { // LEFT SEGMENT
			for (int k = j + 1; k < n + 1; k++) { // RIGHT SEGMENT
				if ( (prf[i]^prf[j]) > (prf[j]^prf[k]) ) {
					answer = min(answer, k - i - 2);
					// break;
				}
			}
		}
	}

	if (answer == INT_MAX) cout << "-1";
	else cout << answer;
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