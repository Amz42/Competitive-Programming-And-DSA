// Question: https://codeforces.com/contest/1539/problem/B

#include <bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define mkpr        make_pair
#define all(v)      v.begin(),v.end()
using namespace std;


const int ten5 = (1e5);
const int MOD = (1e9 + 7);



void answer_nikalo() {
    int n, q; cin >> n >> q;
    string s; cin >> s;

    ll int a[n + 1] {0};
    for (int i = 0; i < n; i++)
        a[i + 1] = a[i] + s[i] - 'a' + 1;

    while (q--) {
        int l, r; cin >> l >> r;
        cout << a[r] - a[l - 1] << endl;
    }
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