// Question: https://codeforces.com/contest/1509/problem/B
// Solution-1: https://codeforces.com/contest/1509/submission/113220362
// Solution-2: https://codeforces.com/contest/1509/submission/113261405

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





///////////////////////////////////////////////////////////////////////////////////////////
///////////////////     Solution - 1
///////////////////////////////////////////////////////////////////////////////////////////
void solve() {
	int n; cin >> n;
	string s; cin >> s;

	set<int> t, m;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'T') t.insert(i);
		else m.insert(i);
	}

	if (t.size() != 2 * m.size()) {
		cout << "NO"; NL
		return;
	}

	for (auto k : m) {
		auto ft = t.begin();
		if (*ft < k) t.erase(ft);
		else {
			cout << "NO"; NL
			return;
		}
	}

	for (auto k : m) {
		auto lt = t.lower_bound(k);
		if (lt != t.end() && *lt > k)
			t.erase(lt);
		else {
			cout << "NO"; NL
			return;
		}
	}

	if (t.size()) cout << "NO";
	else cout << "YES";
	NL
	return;
}
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////     Solution - 1
///////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////
///////////////////     Solution - 2
///////////////////////////////////////////////////////////////////////////////////////////
bool check(string s) {
	int t = 0, m = 0;
	for (auto k : s) {
		(k == 'T' ? t++ : m++);
		if (t < m) return false;
	}
 
	return true;
}
 
void solve2() {
	int n; cin >> n;
	string s; cin >> s;
	int t = 0, m = 0;
	for (auto k : s) (k == 'T' ? t++ : m++);
 
	string rs = s; reverse(rs.begin(), rs.end());
	if (t == 2 * m && check(s) && check(rs)) cout << "YES";
	else cout << "NO";
	NL
	return;
}
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////     Solution - 2
///////////////////////////////////////////////////////////////////////////////////////////




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