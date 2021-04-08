// Question: https://www.codechef.com/problems/XORSUB
// Solution: https://www.codechef.com/viewsolution/44766384

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
vector<int> a;
int dp[1001][1025];
int fun(int index, int XOR) {
	if (index == n) return XOR ^ k;
	if (dp[index][XOR] != -1) return dp[index][XOR];
	return dp[index][XOR] = max(fun(index + 1, XOR), fun(index + 1, XOR ^ a[index]));
}

void solve() {
	cin >> n >> k;

	memset(dp, -1, sizeof dp);
	a.resize(n); for (auto &g : a) cin >> g;

	// index = 0, initial XOR = 0
	cout << fun(0, 0); NL
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