// Question: https://codeforces.com/contest/1538/problem/C
// Solution: https://codeforces.com/contest/1538/submission/119036328

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
    ll int n, l, r; cin >> n >> l >> r;

    vector<ll int> v(n);
    for (auto &k : v) cin >> k;

    sort(v.begin(), v.end());
    ll int answer = 0, imxxx = 0;
    for (int i = 0; i < n; i++) {
        ll int x = lower_bound(v.begin(), v.end(), l - v[i]) - v.begin();
        ll int y = upper_bound(v.begin(), v.end(), r - v[i]) - v.begin();

        if (x <= i && i < y) imxxx++;
        answer += (y - x);
    }

    cout << (ll int)( (answer - imxxx) / 2); NL
    return;
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