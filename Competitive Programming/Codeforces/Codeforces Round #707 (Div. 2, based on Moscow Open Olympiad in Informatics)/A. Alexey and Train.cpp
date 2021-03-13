// Question: https://codeforces.com/contest/1501/problem/A
// Solution: https://codeforces.com/contest/1501/submission/109864567

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
	int N; cin >> N;
	vector<pair<int, int>> pairs_time(N);
	for (auto &k : pairs_time) cin >> k.first >> k.second;

	int previous_delay = 0; int current_delay;
	for (int i = 0; i < N; i++) {
		cin >> current_delay;
		int Actual_arrival = pairs_time[i].first + previous_delay + current_delay;
		int Actual_Departure = max(pairs_time[i].second, Actual_arrival + (pairs_time[i].second - pairs_time[i].first + 1) / 2);
		previous_delay = Actual_Departure - pairs_time[i].second;
		if (i == N - 1) cout << Actual_arrival << endl;
	}

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