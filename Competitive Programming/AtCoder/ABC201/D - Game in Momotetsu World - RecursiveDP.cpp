// Question: https://atcoder.jp/contests/abc201/tasks/abc201_d
// Solution: https://atcoder.jp/contests/abc201/submissions/22639863

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


int n, m;
int A[2000][2000];
int dp[2000][2000];

int fun(int i, int j) {
    int turn = !((i + j) % 2);
    if (i == n - 1 && j == m - 1)
        return 0;
    if (i >= n || j >= m)
        return (turn == 1 ? 1e8 : -1e8);
    if (dp[i][j] != INT_MIN)
        return dp[i][j];

    int answer;
    if (turn == 1)
        answer = max(
                     (i + 1 < n ? A[i + 1][j] + fun(i + 1, j) : -1e8),
                     (j + 1 < m ? A[i][j + 1] + fun(i, j + 1) : -1e8)
                 );
    else
        answer = min(
                     (i + 1 < n ?  fun(i + 1, j) - A[i + 1][j] : 1e8),
                     (j + 1 < m ?  fun(i, j + 1) - A[i][j + 1] : 1e8)
                 );
    return dp[i][j] = answer;
}

void solve(int tc) {
    cin >> n >> m;
    fori(0, n) {
        string s; cin >> s;
        forj(0, m) {
            A[i][j] = (s[j] == '+' ? +1 : -1);
            dp[i][j] = INT_MIN;
        }
    }

    int x = fun(0, 0);

    if (x == 0)
        cout << "Draw";
    else if (x > 0)
        cout << "Takahashi";
    else
        cout << "Aoki";
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