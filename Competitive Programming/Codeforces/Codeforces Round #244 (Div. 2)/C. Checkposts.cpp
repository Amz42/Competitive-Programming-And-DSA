// Question: https://codeforces.com/contest/427/problem/C
// Solution: https://codeforces.com/contest/427/submission/114485332

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

// KOSARAJU'S ALGORITHM

const int NODES = 1e5 + 1;
vector<int> graph[NODES], trans[NODES];
bool visited[NODES];
int cost[NODES];
vector<int> order;


void dfs1(int node) {
    visited[node] = 1;

    for (int child : graph[node])
        if (visited[child] == 0)
            dfs1(child);

    order.pb(node);
}

int expense, cnt;
void dfs2(int node) {
    visited[node] = 0;

    if (cost[node] < expense) expense = cost[node], cnt = 1;
    else if (cost[node] == expense) cnt++;

    for (int child : trans[node])
        if (visited[child] == 1)
            dfs2(child);
}

void solve(int tc) {
    int n, m, x, y; cin >> n;
    fori(0, n) cin >> cost[i];
    cin >> m;
    while (m--) cin >> x >> y, --x, --y, graph[x].pb(y), trans[y].pb(x);

    fori(0, n) if (visited[i] == 0) dfs1(i);

    ll int ways = 1, answer = 0;
    fori(0, n) {
        int node = order[n - i - 1];
        if (visited[node] == 1) {
            cnt = 1;
            expense = INT_MAX;
            dfs2(node);

            answer += expense;
            ways = (ways * cnt) % MOD;
        }
    }

    cout << answer << " " << ways;
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