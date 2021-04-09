// (SPOJ) Question: https://www.spoj.com/problems/MPILOT/
// (SPOJ) Solution: https://www.spoj.com/status/ns=27676164
// (CodeForces) Question: https://codeforces.com/group/FLVn1Sc504/contest/274509/problem/C
// (CodeForces) Solution: https://codeforces.com/group/FLVn1Sc504/contest/274509/my#

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



// a[][0] = captain
// a[][1] = assistant
int n;
int a[10001][2];
int dp[10001][5001];

int fun(int index, int assistants, int captains) {
	if (index == n) return 0;
	if (dp[index][assistants] != -1) return dp[index][assistants];

	int answer;
	// we have to choose a captain | AS all assistants are chosen
	if (assistants == n / 2)
		answer = a[index][0] + fun(index + 1, assistants, captains + 1);
	// we have to choose an assistant
	else if (assistants == captains)
		answer = a[index][1] + fun(index + 1 , assistants + 1, captains);
	else
		answer = min(
		             a[index][0] + fun(index + 1, assistants, captains + 1), // choosing captain
		             a[index][1] + fun(index + 1 , assistants + 1, captains) // choosing assistant
		         );

	return dp[index][assistants] = answer;
}

void solve() {
	memset(dp, -1, sizeof dp);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];

	dp[0][0] = a[0][1] + fun(1, 1, 0);
	cout << dp[0][0]; NL
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