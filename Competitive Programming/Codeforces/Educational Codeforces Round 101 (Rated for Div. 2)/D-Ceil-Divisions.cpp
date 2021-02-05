// Question: https://codeforces.com/contest/1469/problem/D
// Solution: https://codeforces.com/contest/1469/submission/102673271

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



vector<pair<int, int>> answer;

void fun(int n) {
	if (n <= 2) return;
	int rt = ceil(sqrt(n));

	for (int i = rt + 1; i < n; i++) answer.push_back({i, n});
	answer.push_back({n, rt});
	answer.push_back({n, rt});

	fun(rt);
}

void solve() {
	int n; cin >> n;
	answer.clear();

	fun(n);

	cout << answer.size(); NL
	for (auto k : answer) cout << k.first << " " << k.second << "\n";
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