// Question: https://atcoder.jp/contests/dp/tasks/dp_l
// Solution: https://atcoder.jp/contests/dp/submissions/22575665

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
    ll int dp[n][n][2];

    for (int len = 1; len <= n; len++) {
        for (int index = len - 1; index < n; index++) {
            int l = index - len + 1;
            int r = index;
            if (len == 1) {
                dp[l][r][0] = a[index];
                dp[l][r][1] = -a[index];
                continue;
            }

            dp[l][r][0] = max(a[l] + dp[l + 1][r][1], a[r] + dp[l][r - 1][1]);
            dp[l][r][1] = min(dp[l + 1][r][0] - a[l], dp[l][r - 1][0] - a[r]);
        }
    }

    cout << dp[0][n - 1][0];
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