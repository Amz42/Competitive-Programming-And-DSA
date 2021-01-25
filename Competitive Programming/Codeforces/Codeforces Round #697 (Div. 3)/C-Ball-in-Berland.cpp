// Question: https://codeforces.com/contest/1475/problem/C
// Solution: https://codeforces.com/contest/1475/submission/105410951

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



ll int nC2(ll int n) {
	return ( n * (n - 1) ) / 2;
}


void solve() {
	int k, a, b; cin >>  a >> b >> k;
	vector<int> boys(a + 1, 0), girls(b + 1, 0);

	int x;
	fori(0, k) cin >> x, boys[x]++;
	fori(0, k) cin >> x, girls[x]++;

	ll int answer = nC2(k);
	fori(0, a) answer -= ( boys[i + 1] >= 2 ? nC2(boys[i + 1]) : 0 );
	fori(0, b) answer -= ( girls[i + 1] >= 2 ? nC2(girls[i + 1]) : 0 );

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