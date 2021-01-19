// Question: https://codeforces.com/contest/1474/problem/B
// Solution: https://codeforces.com/contest/1474/submission/104795815

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



///////////////////////////// SIEVE OF ERATOSTHENES | Amz42
const int sieve_N = 1e6;
bool is_prime[sieve_N + 1];
void sieve() {
	memset(is_prime, true, sizeof(is_prime));
	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i * i <= sieve_N; i++) {
		if (is_prime[i]) {
			for (int j = i * i; j <= sieve_N; j += i) {
				is_prime[j] = 0;
			}
		}
	}
}
///////////////////////////// SIEVE OF ERATOSTHENES | Amz42

vector<ll int>primes;

void solve() {
	ll int d; cin >> d;
	ll int num1 = *lower_bound(primes.begin(), primes.end(), (1 + d) );
	ll int num2 = *lower_bound(primes.begin(), primes.end(), (num1 + d) );
	cout << num1*num2; NL
	return;
}






int main() {
	optimize
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	long long int tests = 1;
	sieve();
	fori(0, sieve_N + 1) if (is_prime[i]) primes.pb(i);
	cin >> tests;

	for (ll int test_case = 1; test_case <= tests; test_case++) {
		solve();
	}

	cerr << "Execution Time : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}