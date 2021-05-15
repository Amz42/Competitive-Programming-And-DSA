// Question: https://atcoder.jp/contests/abc201/tasks/abc201_d
// Solution: https://atcoder.jp/contests/abc201/submissions/22640454

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
    int A[n][m], dp[n][m];
    fori(0, n) {
        string s; cin >> s;
        forj(0, m) {
            A[i][j] = (s[j] == '+' ? +1 : -1);
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (i == n - 1 && j == m - 1) {
                dp[i][j] = 0;
                continue;
            }

            int answer;

            if ((i + j) % 2 == 0) { // Takahashi's Move
                answer = INT_MIN;
                if (i + 1 < n) answer = max(answer, A[i + 1][j] + dp[i + 1][j]);
                if (j + 1 < m) answer = max(answer, A[i][j + 1] + dp[i][j + 1]);
            } else { // Aoki's Move
                answer = INT_MAX;
                if (i + 1 < n) answer = min(answer, dp[i + 1][j] - A[i + 1][j]);
                if (j + 1 < m) answer = min(answer, dp[i][j + 1] - A[i][j + 1]);
            }

            dp[i][j] = answer;
        }
    }

    int answer = dp[0][0];
    if (answer > 0)
        cout << "Takahashi";
    else if (answer < 0)
        cout << "Aoki";
    else
        cout << "Draw";
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