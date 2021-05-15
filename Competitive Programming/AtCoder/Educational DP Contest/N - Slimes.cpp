// Question: https://atcoder.jp/contests/dp/tasks/dp_n
// Solution: https://atcoder.jp/contests/dp/submissions/22586877

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
    ll int a[n]; fori(0, n) cin >> a[i];


    ll int dp[n + 1][n + 1];

    ll int last = 0;
    for (int i = 0; i < n; i++)
        last = a[i] = last + a[i];

    for (int len = 1; len <= n; len++) {
        for (int index = len - 1; index < n; index++) {
            int l = index - len + 1;
            int r = index;

            if (l == r) {
                dp[l][r] = 0;
                continue;
            }

            dp[l][r] = LLONG_MAX;

            for (int partition = l; partition < r; partition++)
                dp[l][r] = min(dp[l][r], dp[l][partition] + dp[partition + 1][r] + a[r] - (l > 0 ? a[l - 1] : 0));
        }
    }

    cout << dp[0][n - 1];
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