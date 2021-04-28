// Question: https://cses.fi/problemset/task/1192
// Solution: https://cses.fi/problemset/result/2057867/

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
 
 
int dim[][2] = {
    { -1, 0}, // up
    { +1, 0}, // down
    {0, -1}, // left
    {0, +1} // right
};
 
bool valid(int i, int j, int n, int m) {
    return !(i < 0 || j < 0 || i >= n || j >= m);
}
 
void dfs(int i, int j, vector<vector<char>>& a, vector<vector<bool>>& visited) {
    visited[i][j] = true;
    for (int k = 0; k < 4; k++) {
        int x = i + dim[k][0];
        int y = j + dim[k][1];
        if (valid(x, y, a.size(), a[0].size()) && a[x][y] != '#' && !visited[x][y])
            dfs(x, y, a, visited);
    }
}
 
void solve(int tc) {
    int n, m; cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j], visited[i][j] = false;
 
    int rooms = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!visited[i][j] && a[i][j] == '.')
                dfs(i, j, a, visited), rooms++;
    cout << rooms;
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