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



bool isPrime(ll int n) {
	for (ll int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}


void solve(int tc) {
	ll int n; cin >> n;
	ll int sq = sqrt(n);

	ll int l = max(2LL, sq - 1000);
	ll int h = sq + 1000;

	vector<ll int> v;
	for (ll int i = l; i <= h; i++) {
		if (isPrime(i)) v.pb(i);
	}

	ll int answer = 0;
	for (ll int i = 1; i < v.size(); i++) {
		if (v[i - 1]*v[i] <= n) answer = v[i - 1] * v[i];
	}

	cout << "Case #" << tc << ": " << answer; NL
}






int main() {
	optimize
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	long long int tests = 1;

	cin >> tests;

	for (ll int test_case = 1; test_case <= tests; test_case++) {
		solve(test_case);
	}

	// cerr << "Execution Time : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}