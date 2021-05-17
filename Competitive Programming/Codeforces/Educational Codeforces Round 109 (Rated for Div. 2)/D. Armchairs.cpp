// Question: https://codeforces.com/contest/1525/problem/D
// Solution: https://codeforces.com/contest/1525/submission/116401059

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


int dp[2505][5001];
vector<int> ones, zeroes;

int fun(int one, int zero) {
    if (one == -1)
        return 0;
    if (zero == -1)
        return 1e9;
    if (dp[one][zero] != -1)
        return dp[one][zero];

    int answer = min({
        abs(ones[one] - zeroes[zero]) + fun(one - 1, zero - 1) ,
        fun(one, zero - 1)
    });

    return dp[one][zero] = answer;
}

void solve(int tc) {
    int n, x; cin >> n;
    fori(0, 2505) forj(0, 5001) dp[i][j] = -1;

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x) ones.push_back(i);
        else zeroes.push_back(i);
    }

    cout << fun(ones.size() - 1, zeroes.size() - 1);
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