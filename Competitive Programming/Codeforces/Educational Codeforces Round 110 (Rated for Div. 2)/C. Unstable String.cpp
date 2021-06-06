// Question: https://codeforces.com/contest/1535/problem/C
// Solution: https://codeforces.com/contest/1535/submission/118505315

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
    string s; cin >> s;
    ll int n = s.size();

    ll int answer = 0;
    ll int l = 0, r = 0;

    ll int _0 = 0, _1 = 0;
    ll int one = 0, zero = 0;

    while (r < n) {
        if (s[r] != '?') {
            ll int e = (s[r] == '0' ? 0 : 1);
            ll int parity = ( (r & 1) ? 1 : -1);
            while (
                l < r &&
                (
                    (e == 0 && _0 != parity && _0 != 0) ||
                    (e == 0 && _1 == parity && _1 != 0) ||
                    (e == 1 && _1 != parity && _1 != 0) ||
                    (e == 1 && _0 == parity && _0 != 0)
                )
            ) {
                if (s[l] != '?') {
                    ll int e2 = (s[l] == '0' ? 0 : 1);
                    if (e2 == 0) zero--;
                    else one--;

                    if (one == 0) _1 = 0;
                    if (zero == 0) _0 = 0;
                }
                l++;
            }

            if (e) _1 = parity, one++;
            else _0 = parity, zero++;
        }

        ll int len = r - l + 1;
        answer += len;
        r++;
    }

    cout << answer; NL
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