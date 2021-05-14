// Question: https://atcoder.jp/contests/dp/tasks/dp_e
// Solution: https://atcoder.jp/contests/dp/submissions/22564737

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





ll int dp[100][(int)(1e5 + 1)];
void solve(int tc) {
    int n, w; cin >> n >> w;
    fori(0, 100) forj(0, 1e5 + 1) dp[i][j] = INT_MAX;

    ll int wt[n], val[n];
    fori(0, n) cin >> wt[i] >> val[i];

    int answer = (wt[0] <= w ? val[0] : 0);
    dp[0][0] = 0; dp[0][val[0]] = wt[0];
    for (int i = 1; i < n; i++) {
        // if no value is there then no weight is there;
        dp[i][0] = 0;
        for (int j = 1; j <= 1e5; j++) {

            dp[i][j] = dp[i - 1][j];

            if (j >= val[i])
                dp[i][j] = min(dp[i][j], wt[i] + dp[i - 1][j - val[i]]);

            if (dp[i][j] <= w)
                answer = max(answer, j);
        }
    }

    cout << answer;
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