// Question: https://codeforces.com/contest/1519/problem/D
// Solution: https://codeforces.com/contest/1519/submission/114630666

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
    vector<ll int> a(n + 2, 0), b(n + 2, 0);
    vector<ll int> pref(n + 2, 0), suff(n + 2, 0);

    fori(1, n + 1) cin >> a[i];
    fori(1, n + 1) cin >> b[i];
    fori(1, n + 1) pref[i] = pref[i - 1] + a[i] * b[i];
    for (int i = n; i > 0; i--) suff[i] = suff[i + 1] + a[i] * b[i];

    // for (auto k : a) cout << k << " "; NL
    // for (auto k : b) cout << k << " "; NL
    // for (auto k : pref) cout << k << " "; NL
    // for (auto k : suff) cout << k << " "; NL
    ll int dp[n + 5][n + 5];
    memset(dp, 0, sizeof dp);
    fori(1, n + 1) dp[i][i] = a[i] * b[i];

    ll int answer = pref[n];
    fori(2, n + 1) {
        forj(2, i + 1) {
            int r = i;
            int l = r - j + 1;
            dp[l][r] = dp[l + 1][r - 1] + a[l] * b[r] + b[l] * a[r];
            answer = max(answer, pref[l - 1] + dp[l][r] + suff[r + 1]);
        }
    }

    // fori(0, n + 2) {
    //     forj(0, n + 2) {
    //         cout << dp[i][j] << " ";
    //     }
    //     NL
    // }
    // NL NL

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