// Question: https://www.codechef.com/problems/PRGCUP01
// Solution: https://www.codechef.com/viewsolution/45499142

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




bool valid(int i, int j) {
    return !(i < 0 || j < 0 || i >= 9 || j >= 9);
}

int dim[][2] = {
    { -2, -1}, //up-left
    { -2, +1}, //up-right
    { -1, +2}, //right-up
    { +1, +2}, //right-down
    { +2, +1}, //down-right
    { +2, -1}, //down-left
    { +1, -2}, //left-down
    { -1, -2} //left-up
};

void solve(int tc) {
    char a, b;
    int sr, sc, dr, dc;
    cin >> a >> sc >> b >> dc;
    sr = a - 'a' + 1;
    dr = b - 'a' + 1;
    // cout << sr << sc << dr << dc; NL

    vector<vector<bool>> visited(9, vector<bool>(9, false));
    visited[sr][sc] = true;

    int lvl = 0;
    queue<pair<int, int>> q; q.push({sr, sc});
    while (!q.empty()) {
        int qsize = q.size();
        while (qsize--) {
            auto k = q.front(); q.pop();
            int i = k.first;
            int j = k.second;

            for (int g = 0; g < 8; g++) {
                int x = i + dim[g][0];
                int y = j + dim[g][1];
                if (valid(x, y) && !visited[x][y]) {
                    if (x == dr && y == dc) {
                        cout << lvl + 1; NL
                        return;
                    }
                    visited[x][y] = true;
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

    cin >> tests;

    for (ll int test_case = 1; test_case <= tests; test_case++) {
        solve(test_case);
    }

    // cerr << "Execution Time : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}