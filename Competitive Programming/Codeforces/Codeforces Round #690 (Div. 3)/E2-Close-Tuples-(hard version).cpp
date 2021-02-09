// Question: https://codeforces.com/contest/1462/problem/E2
// Solution: https://codeforces.com/contest/1462/submission/101476611

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




const int fact_N = (int)(2e5 + 5);
long long factorialNumInverse[fact_N], naturalNumInverse[fact_N], fact[fact_N];
void InverseofNumber(long long p) {
	naturalNumInverse[0] = naturalNumInverse[1] = 1;
	for (int i = 2; i <= fact_N; i++)
		naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
void InverseofFactorial(long long p) {
	factorialNumInverse[0] = factorialNumInverse[1] = 1;
	for (int i = 2; i <= fact_N; i++)
		factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}
void factorial(long long p) {
	fact[0] = 1;
	for (int i = 1; i <= fact_N; i++) {
		fact[i] = (fact[i - 1] * i) % p;
	}
}
long long nCr(long long fact_N, long long R, long long p) {
	long long ans = ((fact[fact_N] * factorialNumInverse[R]) % p * factorialNumInverse[fact_N - R]) % p;
	return ans;
}
// call "precompute" function at the start of the program inside main()
void precompute(long long int mod = (long long int)(1e9 + 7)) {
	InverseofNumber(mod);
	InverseofFactorial(mod);
	factorial(mod);
}




void solve() {
	ll int n, m, k; cin >> n >> m >> k;
	vector<ll int> v(n); for (auto &i : v) cin >> i;
	sort(v.begin(), v.end());

	ll int answer = 0;
	fori(0, n) {
		ll int position = upper_bound(v.begin(), v.end(), v[i] + k) - v.begin();
		ll int numbers = position - i;
		if (numbers - 1 >= m - 1) {
			answer = (answer + nCr(numbers - 1, m - 1, MOD)) % MOD;
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

	precompute();

	long long int tests = 1;

	cin >> tests;

	for (ll int test_case = 1; test_case <= tests; test_case++) {
		solve();
	}

	cerr << "Execution Time : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}