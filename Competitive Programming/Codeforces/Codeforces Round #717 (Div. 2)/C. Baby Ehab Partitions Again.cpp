// Question: https://codeforces.com/contest/1516/problem/C
// Solution: https://codeforces.com/contest/1516/submission/113802999

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



bool fun(vector<int>& v, int sum) {
	bool dp[sum + 1] = {0}; dp[0] = 1;

	for (int i = 0; i < v.size(); i++) {
		for (int j = sum; j >= 0; j--) {
			if (j - v[i] >= 0)
				dp[j] = dp[j - v[i]] || dp[j];
		}
	}

	return dp[sum];
}


void solve(int tc) {
	int n; cin >> n;
	int sum = 0, od = -1;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
		if (v[i] & 1) od = i + 1;
	}

	if ( (sum & 1) || !fun(v, sum / 2)) {
		cout << "0";
		return;
	}

	if (od != -1) {
		cout << 1; NL
		cout << od;
		return;
	}

	for (int i = 0; i < n; i++) {
		int sm = sum - v[i];
		int e = v[i];
		v[i] = 0;
		if (!fun(v, sm / 2)) {
			cout << 1; NL
			cout << i + 1;
			return;
		}
		v[i] = e;
	}

	cout << "0";
	return;
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
		solve(test_case);
	}

	// cerr << "Execution Time : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}