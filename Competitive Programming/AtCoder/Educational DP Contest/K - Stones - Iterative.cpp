// Question: https://atcoder.jp/contests/dp/tasks/dp_k
// Solution: https://atcoder.jp/contests/dp/submissions/22573877

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
    int n, k; cin >> n >> k;
    int a[n]; fori(0, n) cin >> a[i];
    bool dp[k + 1][2];

    for (int i = 0; i <= k; i++) {
        dp[i][0/*Jiro*/] = 1/*Taro wins*/;
        dp[i][1/*Taro*/] = 0/*Jiro wins*/;

        // Calculation for Jiro
        forj(0, n) {
            if (i < a[j]) break;
            if (dp[i - a[j]][1] == 0) {
                dp[i][0] = 0;
                break;
            }
        }

        // Calculation for Taro
        forj(0, n) {
            if (i < a[j]) break;
            if (dp[i - a[j]][0] == 1) {
                dp[i][1] = 1;
                break;
            }
        }
    }

    cout << (dp[k][1] ? "First" : "Second");
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