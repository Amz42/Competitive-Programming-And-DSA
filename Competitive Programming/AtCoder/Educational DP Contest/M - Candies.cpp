// Question: https://atcoder.jp/contests/dp/tasks/dp_m
// Solution: https://atcoder.jp/contests/dp/submissions/22580859

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






void solve(int tc) {
    int n, k; cin >> n >> k;
    int a[n]; fori(0, n) cin >> a[i];

    int dp[n][k + 1]; memset(dp, 0, sizeof dp);
    for (int candy = 0; candy <= a[0]; candy++) dp[0][candy] = 1; /*only one way*/

    for (int stud = 1; stud < n; stud++) {
        // calculating prefix sum
        int pref[k + 1]; pref[0] = dp[stud - 1][0];
        for (int i = 1; i <= k; i++) pref[i] = (pref[i - 1] + dp[stud - 1][i]) % MOD;

        for (int candy = 0; candy <= k; candy++) {
            if (candy > a[stud]) {
                dp[stud][candy] = (pref[candy] + MOD - pref[candy - a[stud] - 1]) % MOD;
            } else {
                dp[stud][candy] = pref[candy];
            }
        }
    }

    cout << dp[n - 1][k];
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
        solve(test_case);
    }

    // cerr << "Execution Time : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}