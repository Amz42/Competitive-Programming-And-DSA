// Question: https://atcoder.jp/contests/dp/tasks/dp_l
// Solution: https://atcoder.jp/contests/dp/submissions/22575182

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



int n;
ll int a[3001];
ll int dp[3001][3001][2];

ll int fun(int l, int r, bool isTaro) {
    if (l > r) return 0;

    if (dp[l][r][isTaro] != LLONG_MIN)
        return dp[l][r][isTaro];

    ll int ans;
    if (isTaro) {
        ans = max(a[l] + fun(l + 1, r, !isTaro) , a[r] + fun(l, r - 1, !isTaro));
    } else {
        ans = min(fun(l + 1, r, !isTaro) - a[l] , fun(l, r - 1, !isTaro) - a[r]);
    }

    return dp[l][r][isTaro] = ans;
}

void solve(int tc) {
    cin >> n;
    fori(0, n) cin >> a[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j][0] = dp[i][j][1] = LLONG_MIN;
        }
    }

    cout << fun(0, n - 1, 1);
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