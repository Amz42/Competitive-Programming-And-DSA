// Question: https://atcoder.jp/contests/dp/tasks/dp_c
// Solution: https://atcoder.jp/contests/dp/submissions/22564536

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
    int n; cin >> n;
    int A[n], B[n], C[n];

    fori(0, n) cin >> A[i] >> B[i] >> C[i];

    int dp[n][3];
    dp[0][0] = A[0]; dp[0][1] = B[0]; dp[0][2] = C[0];

    for (int i = 1; i < n; i++) {
        dp[i][0] = A[i] + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = B[i] + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = C[i] + max(dp[i - 1][0], dp[i - 1][1]);
    }

    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
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