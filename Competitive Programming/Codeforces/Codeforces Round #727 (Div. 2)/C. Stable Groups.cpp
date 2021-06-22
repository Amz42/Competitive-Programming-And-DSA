// Question: https://codeforces.com/contest/1539/problem/C

#include <bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define mkpr        make_pair
#define all(v)      v.begin(),v.end()
using namespace std;


const int ten5 = (1e5);
const int MOD = (1e9 + 7);



void answer_nikalo() {
    ll int n, k, x; cin >> n >> k >> x;
    vector<ll int> v(n); for (auto &g : v) cin >> g;
    sort(v.begin(), v.end());

    int grp = 0;
    vector<ll int> a;
    ll int last = -5 * 1e18;

    for (int i = 0; i < n; i++) {
        if (v[i] - last > x) {
            grp++;
            if (i) a.push_back(((v[i] - last) / x) - !((v[i] - last) % x));
        }
        last = v[i];
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < a.size(); i++) {
        k -= a[i];
        if (k < 0) break;
        grp--;
    }

    cout << max(1, grp);
}






int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int test_cases = 1;

    // cin >> test_cases;

    while (test_cases-- > 0) {
        answer_nikalo();
    }

    cerr << "RUN Time : " << (float)clock() / CLOCKS_PER_SEC << " seconds\n";
    return 0;
}