// Question: https://codeforces.com/problemset/problem/1110/D
// Solution: https://codeforces.com/contest/1110/submission/116135586

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


int n, m, x;
int freq[(int)(1e6 + 5)];
int dp[(int)(1e6 + 5)][5][3];

int fun(int e, int e_used, int e1_used) {
    // base case (more count of e or (e+1) is used than available)
    if (freq[e] < e_used || freq[e + 1] < e1_used)
        return INT_MIN;

    // if all elements are used up
    if (e > m) return 0;

    // if pre-calculated
    if (dp[e][e_used][e1_used] != -1)
        return dp[e][e_used][e1_used];

    // freqency of (e) remaining
    int e_freq = freq[e] - e_used;

    // Forming Triplets:

    // type1 = {(e,e,e) x n-times}
    int type1 = (e_freq / 3) + fun(e + 1, e1_used, 0);

    // type2 = {(e,e+1,e+2) x 1-time}, {(e,e,e) x n-times}
    int type2 = (e_freq >= 1 ? (1 + ((e_freq - 1) / 3) + fun(e + 1, e1_used + 1, 1)) : 0);

    // type2 = {(e,e+1,e+2) x 2-times}, {(e,e,e) x n-times}
    int type3 = (e_freq >= 2 ? (2 + ((e_freq - 2) / 3) + fun(e + 1, e1_used + 2, 2)) : 0);

    return dp[e][e_used][e1_used] = max({type1, type2, type3, 0});
}

void solve(int tc) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> x, freq[x]++;

    memset(dp, -1, sizeof dp);

    cout << fun(1, 0, 0);
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