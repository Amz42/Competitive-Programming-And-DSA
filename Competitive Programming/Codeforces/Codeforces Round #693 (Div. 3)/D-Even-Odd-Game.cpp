// Question: https://codeforces.com/contest/1472/problem/D
// Solution: https://codeforces.com/contest/1472/submission/103260510

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
	ll int n, x; cin >> n;
	priority_queue<ll int> ev, od;

	fori(0, n) {
		cin >> x;
		if (x & 1) od.push(x);
		else ev.push(x);
	}

	bool turn = 1;
	ll int score = 0;
	while (ev.size() > 0 && od.size() > 0) {
		if (turn) { // alice turn
			if (ev.top() >= od.top()) score += ev.top(), ev.pop();
			else od.pop();
		} else { // bob turn
			if (od.top() >= ev.top()) score -= od.top(), od.pop();
			else ev.pop();
		}
		turn ^= 1;
	}

	while (od.size() > 0) {
		if (turn) { // alice turn
			od.pop();
		} else { // bob turn
			score -= od.top(), od.pop();
		}
		turn ^= 1;
	}

	while (ev.size() > 0) {
		if (turn) { // alice turn
			score += ev.top(); ev.pop();
		} else { // bob turn
			ev.pop();
		}
		turn ^= 1;
	}

	if (score < 0) cout << "Bob";
	else if (score > 0) cout << "Alice";
	else cout << "Tie";
	NL
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