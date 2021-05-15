// Question: https://atcoder.jp/contests/dp/tasks/dp_p
// Solution: https://atcoder.jp/contests/dp/submissions/22591389

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


int n, x, y;
vector<int> adj[ten5 + 5];
ll int dp[ten5 + 5][2];

void solve(int tc) {
    cin >> n;
    fori(0, n - 1) cin >> x >> y, adj[x].push_back(y), adj[y].push_back(x);

    function<void(int, int)> dfs = [&](int node, int parent) {
        dp[node][0] = dp[node][1] = 1;

        for (int v : adj[node]) {
            if (v == parent) continue;
            dfs(v, node);

            dp[node][0] = (dp[node][0] * ((dp[v][0] + dp[v][1]) % MOD) ) % MOD;
            dp[node][1] = (dp[node][1] * dp[v][0] ) % MOD;
        }
    };

    dfs(1, -1);

    cout << (dp[1][0] + dp[1][1]) % MOD;
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