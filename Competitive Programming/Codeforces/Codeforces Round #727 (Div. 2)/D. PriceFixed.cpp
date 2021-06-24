// Question: https://codeforces.com/contest/1539/problem/D

#include <bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define mkpr        make_pair
#define all(v)      v.begin(),v.end()
using namespace std;


const int ten5 = (1e5);
const int MOD = (1e9 + 7);


typedef pair<ll int, ll int> plli;
void answer_nikalo() {
    ll int n; cin >> n;
    vector<plli> v(n);
    for (auto &k : v) cin >> k.second >> k.first;
    sort(v.begin(), v.end());

    int l = 0, r = n - 1;
    ll int cost = 0, items = 0;

    while (l < r) {
        if (v[l].first > items) {
            ll int mn = min(v[l].first - items, v[r].second);
            cost += 2 * mn;
            v[r].second -= mn;
            if (v[r].second == 0) r--;
            items += mn;
        } else {
            cost += v[l].second;
            items += v[l].second;
            v[l].second = 0;
            l++;
        }
    }

    if (l == r) {
        ll int mn = max(0LL, min(v[l].first - items, v[l].second));
        cost += 2 * mn;
        v[l].second -= mn;
        cost += v[l].second;
    }

    cout << cost;
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