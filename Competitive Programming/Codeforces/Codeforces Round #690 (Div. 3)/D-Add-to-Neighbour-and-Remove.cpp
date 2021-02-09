// Question: https://codeforces.com/contest/1462/problem/D
// Solution: https://codeforces.com/contest/1462/submission/101386940

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



int fun(vector<ll int> v, ll int sum) {
	int operations = 0;
	int ptr = 0;

	while (ptr < v.size()) {
		ll int x = v[ptr++];
		while (ptr < v.size() && x < sum) {
			x += v[ptr++];
			operations++;
		}

		if (x != sum) return INT_MAX;
	}

	return operations;
}


void solve() {
	int n; cin >> n;
	vector<ll int> v(n);
	ll int sum = 0 ;
	for (auto &i : v) cin >> i, sum += i;

	int answer = INT_MAX;
	for (int div = 1; div * div <= sum; div++) {
		if (sum % div == 0) {
			answer = min({answer, fun(v, div), fun(v, sum / div)});
		}
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

	for (ll int test_case = 1; test_case <= tests; test_case++) {
		solve();
	}

	cerr << "Execution Time : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}