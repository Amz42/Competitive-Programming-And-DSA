// Question: https://www.codechef.com/ZCOPRAC/problems/ZCO12004/
// Solution: https://www.codechef.com/viewsolution/44268614

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




int fun(vector<int> a) {
	int n = a.size();
	int dp[n]; dp[0] = a[0]; dp[1] = a[1];

	for (int i = 2; i < n; i++)
		dp[i] = a[i] + min({ dp[i - 2], dp[i - 1] });

	return dp[n - 1];
}

void solve() {
	int n; cin >> n;
	vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];

	int answer1 = fun(a);
	reverse(a.begin(), a.end());
	int answer2 = fun(a);

	cout << min(answer1, answer2);
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