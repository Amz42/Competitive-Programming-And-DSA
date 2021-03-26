// Question: https://codeforces.com/contest/1506/problem/D
// Solution1: https://codeforces.com/contest/1506/submission/111157658
// Solution2: https://codeforces.com/contest/1506/submission/111160208

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





// Solution 1
void solve() {
	int n, x; cin >> n;
	map<int, int> mp;

	for (int i = 0; i < n; i++) {
		cin >> x;
		mp[x]++;
	}

	priority_queue<pair<int, int>> pq;
	for (auto k : mp) pq.push({k.second, k.first});

	while (pq.size() > 1) {
		auto k = pq.top(); pq.pop();
		auto g = pq.top(); pq.pop();

		k.first--, g.first--;
		if (k.first) pq.push(k);
		if (g.first) pq.push(g);
	}

	if (pq.size()) cout << pq.top().first;
	else cout << "0";
	NL
	return;
}

// Solution 2
void solve2() {
	int n; cin >> n;
	vector<int> v(n);
	for (auto &k : v) cin >> k;

	sort(v.begin(), v.end());

	int l = 0, r = n / 2, answer = n;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		bool okay = true;
		for (int i = 0; i < mid; i++) {
			// i-th & (n-mid+i)-th element are same
			// then they can't cancel out each other
			if (v[i] == v[n - mid + i]) {
				okay = false;
				break;
			}
		}

		if (okay) {
			l = mid + 1;
			answer = min(answer, n - mid * 2);
		} else r = mid - 1;
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