// Question: https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/explosion-2-5f6ef62e/
// Solution: https://www.hackerearth.com/submission/56972302/

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
 
const int NODES = 1e5 + 1;
vector<int> graph[NODES];
bool perfect_matching;
 
int dfs(int node, int parent = -1) {
    int val = 1;
 
    for (auto child : graph[node]) {
        if (child == parent) continue;
        val = val - dfs(child, node);
    }
 
    if (val < 0 || (parent == -1 && val == 1))
        perfect_matching = false;
 
    return val;
}
 
 
void solve(int tc) {
    int n, x, y; cin >> n;
    fori(0, n - 1) cin >> x >> y, graph[x].pb(y), graph[y].pb(x);
 
    perfect_matching = true;
    dfs(1);
 
    cout << ( perfect_matching ? "UNSAFE" : "SAFE"); NL
 
    fori(1, n + 1) graph[i].clear();
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