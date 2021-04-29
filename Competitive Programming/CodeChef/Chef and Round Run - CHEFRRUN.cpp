// Question: https://www.codechef.com/problems/CHEFRRUN
// Solution: https://www.codechef.com/viewsolution/45511594

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
bool visited[(int)1e6 + 1];
vector<int> adj[(int)1e6 + 1];
vector<int> t_adj[(int)1e6 + 1];
vector<int> order;

void dfs1(int node) {
    visited[node] = true;

    for (int child : adj[node])
        if (!visited[child])
            dfs1(child);

    order.push_back(node);
}

int nodes;
void dfs2(int node) {
    visited[node] = true;
    nodes++;

    for (int child : t_adj[node])
        if (!visited[child])
            dfs2(child);
}

void solve(int tc) {
    cin >> n;

    order.clear();
    fori(0, n) adj[i].clear(), t_adj[i].clear(), visited[i] = false;

    int x;
    fori(0, n) {
        int x, y; cin >> x;
        y = (i + x + 1) % n;
        adj[i].push_back(y), t_adj[y].push_back(i);
    }

    int answer = 0;
    fori(0, n) if (!visited[i]) dfs1(i);
    fori(0, n) visited[i] = false;
    fori(0, n) {
        int node = order[n - i - 1];
        if (!visited[ node ]) {
            nodes = 0;
            dfs2(node);
            if (nodes > 1 || adj[node][0] == node)
                answer += nodes;
        }
    }

    cout << answer; NL
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