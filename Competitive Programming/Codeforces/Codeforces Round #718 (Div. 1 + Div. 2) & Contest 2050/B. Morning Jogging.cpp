// Question: https://codeforces.com/contest/1517/submission/114021105
// Solution: https://codeforces.com/contest/1517/submission/114021105

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






void solve(int tc) {
    int n, m; cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    vector<vector<int>> answer(n, vector<int>(m, INT_MAX));

    vector<array<int, 2>> v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            v.push_back({mat[i][j], i});
        }
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < m; i++) {
        answer[v[i][1]][i] = v[i][0];
    }

    for (int i = 0; i < n; i++) {
        vector<int> r = mat[i];
        sort(r.rbegin(), r.rend());
        int index = 0;
        for (int j = 0; j < m; j++) {
            if (answer[i][j] == INT_MAX) {
                answer[i][j] = r[index++];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << answer[i][j] << " ";
        }
        NL
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