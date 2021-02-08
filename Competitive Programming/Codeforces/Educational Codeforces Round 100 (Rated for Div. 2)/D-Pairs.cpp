// Question: https://codeforces.com/contest/1463/problem/D
// Solution: https://codeforces.com/contest/1463/submission/101839456

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



int find_separation(vector<int> &A, vector<int> &B, int n) {
	int l = 0, r = n - 1;
	int answer = 0;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		bool possible = true;
		fori(0, mid + 1) {
			if (A[i] > B[n + i - mid - 1]) {
				possible = false;
				break;
			}
		}

		if (possible) {
			answer = mid + 1;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return answer;
}


void solve() {
	int n, x; cin >> n;
	bool present[2 * n + 1] = {0};
	fori(0, n) cin >> x, present[x] = 1;

	vector<int> A, B;
	fori(1, 2 * n + 1) {
		if (!present[i]) A.push_back(i);
		else B.push_back(i);
	}

	int r = find_separation(A, B, n);
	int l = n - find_separation(B, A, n);

	cout << max(0, r - l + 1); NL
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