// Question: https://codeforces.com/contest/1497/problem/E1
// Solution: https://codeforces.com/contest/1497/submission/110303859

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



int maxN = 1e7 + 1;
vector<int> primeFactor(maxN, 1);
void factorize() {
	for (int i = 2; i < maxN; i++) {
		if (primeFactor[i] == 1) {
			for (int j = i; j < maxN; j += i) {
				primeFactor[j] = i;
			}
		}
	}
}

void solve() {
	int n, w; cin >> n >> w;
	int v[n]; for (int i = 0; i < n; i++) cin >> v[i];

	for (int i = 0; i < n; i++) {
		int x = v[i];
		int count = 0;
		int fac = primeFactor[x]; // largest primeFactor of x
		v[i] = 1; // taking all multiples from x

		while (x > 1) {
			// counting occurence of a number in prime factorization of x
			if (primeFactor[x] == fac) {
				count++;
				x /= fac;
			} else {
				// count is odd then we need to check for
				// elements which don't form pair, so mark them
				if (count & 1) v[i] *= fac;
				fac = primeFactor[x];
				count = 0;
			}
		}

		// still count left & its odd
		// then make it count
		if (count & 1) v[i] *= fac;
	}

	int answer = 1; // at least 1 segment is always there
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		if (mp[v[i]]) { // previously same number appeared
			answer++;
			mp.clear(); // new segment has started
		}
		mp[v[i]]++; // mark presence of this element
	}

	cout << answer; NL
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
	factorize();

	for (ll int test_case = 1; test_case <= tests; test_case++) {
		solve();
	}

	cerr << "Execution Time : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}