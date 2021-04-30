// Question: https://codeforces.com/contest/22/problem/E
// Solution: https://codeforces.com/contest/22/submission/114638790

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


const int  NODES = 1e5 + 1;
int graph[NODES];
bool visited[NODES];
int in_degree[NODES];
vector<pair<int, int>> v;

int dfs(int node) {
    visited[node] = true;

    if (!visited[graph[node]])
        return dfs(graph[node]);
    else
        return node;
}

void solve(int tc) {
    int n, x; cin >> n;
    fori(1, n + 1) cin >> x, graph[i] = x, in_degree[x]++;

    // treat nodes with 0 in_degree first
    fori(1, n + 1) if (in_degree[i] == 0) v.pb({i, dfs(i)});
    int sz = v.size();

    // still any SCC remains in the graph
    fori(1, n + 1) if (!visited[i]) v.pb({i, dfs(i)});

    // graph itself is a single strongly connected component
    if (sz == 0 && v.size() == 1) {
        cout << "0";
        return;
    }

    cout << v.size(); NL
    fori(0, v.size()) {
        cout << v[i].second << " " << v[(i + 1) % v.size()].first; NL
    }
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