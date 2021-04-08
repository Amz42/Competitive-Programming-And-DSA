// Question: https://www.spoj.com/problems/SQRBR/
// Solution: https://www.spoj.com/status/ns=27675572

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




int n, k;
set<int> a;
int dp[51][51];

int fun(int index, int cnt) {
	if (index == 2 * n) return (cnt == 0 ? 1 : INT_MIN);
	if (dp[index][cnt] != -1) return dp[index][cnt];

	int answer = 0;
	if (a.find(index) != a.end()) {
		int x = fun(index + 1, cnt + 1);
		answer = max(0, x);
	} else {
		int x = 0;
		if (cnt) x = fun(index + 1, cnt - 1);
		answer += max(0, x);
		answer += max(fun(index + 1, cnt + 1), 0);
	}

	return dp[index][cnt] = answer;
}

void solve() {
	cin >> n >> k;
	a.clear();
	memset(dp, -1, sizeof dp);
	int x;
	for (int i = 0; i < k; i++) cin >> x, a.insert(--x);

	cout << fun(0, 0); NL
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