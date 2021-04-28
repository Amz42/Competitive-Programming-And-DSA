// Question: https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/jungle-run/
// Solution: https://www.hackerearth.com/submission/56877223/

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
    { -1, 0},
    { +1, 0},
    {0, +1},
    {0, -1},
};
 
 
bool valid(int i, int j, int n) {
    return !(i < 0 || j < 0 || i >= n || j >= n);
}
 
 
void solve(int tc) {
    int n; cin >> n;
    vector<vector<char>> v(n, vector<char>(n));
 
    int startx, starty;
    fori(0, n) {
        forj(0, n) {
            cin >> v[i][j];
            if (v[i][j] == 'S') startx = i, starty = j;
        }
    }
 
    int lvl = 0;
    queue<pair<int, int>> q; q.push({startx, starty});
    while (!q.empty()) {
        int qsize = q.size();
        while (qsize--) {
            auto k = q.front(); q.pop();
            int i = k.first; int j = k.second;
 
            for (int g = 0; g < 4; g++) {
                int x = i + dim[g][0];
                int y = j + dim[g][1];
                if (valid(x, y, n) && (v[x][y] == 'P' || v[x][y] == 'E')) {
                    if (v[x][y] == 'E') {
                        cout << lvl + 1;
                        return;
                    }
                    v[x][y] = 'X';
                    q.push({x, y});
                }
            }
        }
        lvl++;
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