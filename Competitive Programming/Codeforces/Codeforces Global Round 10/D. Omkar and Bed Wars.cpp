// Question: https://codeforces.com/contest/1392/problem/D
// Solution: https://codeforces.com/contest/1392/submission/102027043

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
	int n; cin >> n;
	char ch;
	deque<char> dq;

	int left = 0, right = 0;

	fori(0, n) {
		cin >> ch;
		if (ch == 'L') left++;
		if (ch == 'R') right++;
		dq.push_back(ch);
	}

	if (left == 0 || right == 0) {
		cout << n / 3 + (n % 3 ? 1 : 0); NL
		return;
	}

	int i = 0;
	while (i < n && dq.front() == 'L') {
		dq.push_back('L');
		dq.pop_front();
		i++;
	}

	i = 0;
	while (i < n && dq.back() == 'R') {
		dq.push_front('R');
		dq.pop_back();
		i++;
	}

	int answer = 0;
	while (!dq.empty()) {
		int count = 0;
		while (!dq.empty() && dq.front() == 'R') { count++; dq.pop_front(); }
		count--; dq.pop_front();
		if (count > 1) answer += (count / 3) + (count % 3 == 2 ? 1 : 0);

		count = 0;
		while (!dq.empty() && dq.front() == 'L') { count++; dq.pop_front(); }
		answer += (count / 3) + (count % 3 == 2 ? 1 : 0);
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