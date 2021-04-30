// Question: https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/practice-problems/algorithm/a-walk-to-remember-qualifier2/
// Solution: https://www.hackerearth.com/submission/56942752/

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
 
const int NODES = 1e6 + 1;
int n, m;
vector<int> graph[NODES], trans[NODES];
bool visited[NODES], answer[NODES];
vector<int> order, scc;
 
void dfs1(int node) {
    visited[node] = 1;
 
    for (auto child : graph[node])
        if (visited[child] == 0)
            dfs1(child);
 
    order.pb(node);
}
 
void dfs2(int node) {
    visited[node] = 0;
 
    for (auto child : trans[node])
        if (visited[child] == 1)
            dfs2(child);
 
    scc.pb(node);
}
 
void solve(int tc) {
    cin >> n >> m;
    int x, y;
    while (m--) cin >> x >> y, --x, --y, graph[x].pb(y), trans[y].pb(x);
 
    fori(0, n) if (visited[i] == 0) dfs1(i);
 
    fori(0, n) {
        int node = order[n - i - 1];
        if (visited[node] == 1) {
            scc.clear();
            dfs2(node);
 
            if (scc.size() > 1) for (auto k : scc) answer[k] = 1;
        }
    }
 
    fori(0, n) cout << answer[i] << " ";
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