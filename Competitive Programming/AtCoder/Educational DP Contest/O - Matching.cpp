// Question: https://atcoder.jp/contests/dp/tasks/dp_o
// Solution: https://atcoder.jp/contests/dp/submissions/22589562

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
int a[21][21];
int dp[21][2100000];

bitset<22> vis;
int fun(int index) {
    int mask = vis.to_ullong();
    if (index == n)
        return ((1 << n) - 1 == mask);
    if (dp[index][mask] != -1)
        return dp[index][mask];

    int answer = 0;
    for (int j = 0; j < n; j++) {
        if (a[index][j] && vis[j] == 0) {
            vis[j] = 1;
            answer = (answer + fun(index + 1)) % MOD;
            vis[j] = 0;
        }
    }

    return dp[index][mask] = answer;
}

void solve(int tc) {
    cin >> n;
    fori(0, n) forj(0, n) cin >> a[i][j];
    memset(dp, -1, sizeof dp);
    cout << fun(0);
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