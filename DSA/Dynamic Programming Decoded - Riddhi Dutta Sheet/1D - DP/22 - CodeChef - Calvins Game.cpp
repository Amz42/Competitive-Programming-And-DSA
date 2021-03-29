// Question: https://www.codechef.com/INOIPRAC/problems/INOI1301
// Solution: https://www.codechef.com/viewsolution/44298885

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
	vector<int> forward(n + 1, 0), backward(n + 1, 0), a(n + 1, 0);

	// main array input
	for (int i = 1; i <= n; i++) cin >> a[i];

	// dp for moving forward from k-th box
	for (int i = k + 1; i <= n; i++)
		forward[i] = a[i] + max(forward[i - 1], forward[i - 2]);

	// dp for moving backward
	backward[1] = a[1];
	backward[2] = a[1] + a[2];	// ensuring we always reach '1' position
	for (int i = 3; i <= n; i++)
		backward[i] = a[i] + max(backward[i - 1], backward[i - 2]);

	int answer = backward[k] - a[k]; // we don't move forward
	for (int i = k + 1; i <= n; i++) {
		answer = max({
			answer,
			forward[i] + 	// we would have moved forward in this box
			backward[i]		// max sum for going back to box '1' from here
			- a[i]			// this box's value is counted twice: in forward & backward
		});
	}

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