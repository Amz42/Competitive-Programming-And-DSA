// Question: https://atcoder.jp/contests/dp/tasks/dp_j
// Solution: https://atcoder.jp/contests/dp/submissions/22573185

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


int n, x;
double dp[305][305][305];
double fun(int one, int two, int three) {
    if (
        (one < 0 || two < 0 || three < 0) ||
        (one == 0 && two == 0 && three == 0)
    ) return 0;

    if (dp[one][two][three] != -1e9)
        return dp[one][two][three];

    double exp =
        n +
        one * fun(one - 1, two, three) +
        two * fun(one + 1, two - 1, three) +
        three * fun(one, two + 1, three - 1);

    return dp[one][two][three] = exp / (one + two + three);
}

void solve(int tc) {
    cin >> n;
    int one, two, three; one = two = three = 0;

    fori(0, n) {
        cin >> x;
        if (x == 1) one++;
        if (x == 2) two++;
        if (x == 3) three++;
    }

    for (int i = 0; i < 305; i++)
        for (int j = 0; j < 305; j++)
            for (int k = 0; k < 305; k++)
                dp[i][j][k] = -1e9;

    cout << fixed << setprecision(9) << fun(one, two, three);
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