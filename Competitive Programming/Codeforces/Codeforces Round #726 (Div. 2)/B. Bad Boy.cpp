// Question: https://codeforces.com/contest/1537/problem/B

#include <bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define mkpr        make_pair
#define all(v)      v.begin(),v.end()
using namespace std;


const int ten5 = (1e5);
const int MOD = (1e9 + 7);

ll int dist(ll int x1, ll int y1, ll int x2, ll int y2) {
    return (abs(x2 - x1) + abs(y2 - y1));
}

ll int fun(array<ll int, 4> a, ll int i, ll int j) {
    return (
               dist(a[0], a[1], i, j) +
               dist(a[2], a[3], i, j) +
               dist(a[0], a[1], a[2], a[3])
           );
}

void answer_nikalo() {
    ll int n, m, i, j; cin >> n >> m >> i >> j;

    vector<array<ll int, 4>> v = {
        {1, 1, 1, m},
        {1, 1, n, 1},
        {1, 1, n, m},
        {1, m, n, m},
        {1, m, n, 1},
        {n, 1, n, m}
    };

    array<ll int, 4> answer;

    ll int diff = INT_MIN;
    for (auto k : v) {
        ll int df = fun(k, i, j);
        if (df > diff) {
            diff = df;
            answer = k;
        }
    }

    for (auto k : answer) cout << k << " ";
    cout << endl;
}






int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int test_cases = 1;

    cin >> test_cases;

    while (test_cases-- > 0) {
        answer_nikalo();
    }

    cerr << "RUN Time : " << (float)clock() / CLOCKS_PER_SEC << " seconds\n";
    return 0;
}