// Question: https://www.codechef.com/COOK126C/problems/PTUPLES
// Solution: https://www.codechef.com/viewsolution/41828577

#include <bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define mkpr        make_pair
#define all(v)      v.begin(),v.end()
using namespace std;


const int ten5 = (1e5);
const int MOD = (1e9 + 7);


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
int pref[sieve_N + 1] = {0};

void answer_nikalo() {
	int n; cin >> n;
	cout << pref[n] << endl;
}






int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	sieve();
	for (int i = 3; i + 2 < sieve_N + 1; i++) {
		if (is_prime[i] && is_prime[i + 2]) pref[i + 2]++;
	}

	for (int i = 1; i < sieve_N + 1; i++) pref[i] += pref[i - 1];

	int test_cases = 1;

	cin >> test_cases;

	while (test_cases-- > 0) {
		answer_nikalo();
	}

	cerr << "RUN Time : " << (float)clock() / CLOCKS_PER_SEC << " seconds\n";
	return 0;
}