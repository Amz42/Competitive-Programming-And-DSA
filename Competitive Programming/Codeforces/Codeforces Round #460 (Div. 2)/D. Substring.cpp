// Question: https://codeforces.com/problemset/problem/919/D
// Solution: https://codeforces.com/contest/919/submission/117266968

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


int n, m;
int dp[3 * ten5 + 5][26];
vector<int> graph[3 * ten5 + 5];
bool visited[3 * ten5 + 5], inStack[3 * ten5 + 5];
string s;

int answer = 0;
bool cycle;

void dfs(int node) {
    visited[node] = inStack[node] = true;

    for (auto k : graph[node]) {
        if (inStack[k]) cycle = true;
        if (!visited[k])
            dfs(k);

        for (int i = 0; i < 26; i++)
            dp[node][i] = max({dp[node][i], dp[k][i]});
    }

    dp[node][s[node - 1] - 'a']++;

    for (int i = 0; i < 26; i++)
        answer = max({answer, dp[node][i]});

    inStack[node] = false;
}

void solve(int tc) {
    cin >> n >> m >> s;

    int x, y;
    while (m-- > 0)
        cin >> x >> y, graph[x].push_back(y);

    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs(i);

    cout << (cycle ? -1 : answer);
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