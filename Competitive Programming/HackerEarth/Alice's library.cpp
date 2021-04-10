// Question: https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/katrina-and-library-c2ed51f3/
// Solution: https://www.hackerearth.com/submission/56281257/

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
	string s, a = ""; cin >> s;
	stack<string> st;
	int n = s.size();
 
	for (int i = 0; i < n; i++) {
		if (s[i] == '\\') {
			reverse(a.begin(), a.end());
			a = st.top() + a;
			st.pop();
		} else if (s[i] == '/') {
			st.push(a);
			a = "";
		} else a += s[i];
	}
 
	cout << a;
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