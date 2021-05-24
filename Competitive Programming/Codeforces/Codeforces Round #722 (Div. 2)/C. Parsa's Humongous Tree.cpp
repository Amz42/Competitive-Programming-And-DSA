// Question: https://codeforces.com/contest/1529/problem/C
// Solution: https://codeforces.com/contest/1529/submission/117255379

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
ll int dp[ten5 + 5][2];
ll int val[ten5][2];
vector<int> graph[ten5 + 5];

ll int dfs(int node, bool lORr, int parent) {
    if (dp[node][lORr] != -1)
        return dp[node][lORr];

    ll int answer = 0;

    for (auto k : graph[node]) {
        if (k == parent) continue;

        answer += max({
            dfs(k, 0, node) + abs(val[node][lORr] - val[k][0]),
            dfs(k, 1, node) + abs(val[node][lORr] - val[k][1])
        });
    }

    return dp[node][lORr] = answer;
}



void solve(int tc) {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        graph[i].clear();
        cin >> val[i][0] >> val[i][1];
        dp[i][0] = dp[i][1] = -1;
    }

    int x, y;
    for (int i = 0; i < n - 1; i++)
        cin >> x >> y, graph[x].pb(y), graph[y].pb(x);

    cout << max({
        dfs(1, 0, -1),
        dfs(1, 1, -1)
    }); NL
    return;
}






int main() {
    optimize
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    long long int tests = 1;

    cin >> tests;

    for (ll int test_case = 1; test_case <= tests; test_case++) {
        solve(test_case);
    }

    // cerr << "Execution Time : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}