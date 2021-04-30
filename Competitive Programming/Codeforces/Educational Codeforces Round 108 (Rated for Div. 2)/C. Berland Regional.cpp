// Question: https://codeforces.com/contest/1519/problem/C
// Solution: https://codeforces.com/contest/1519/submission/114583213

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
    int n; cin >> n;
    vector<ll int> v(n);
    map<ll int, vector<ll int>> uni;

    for (int i = 0; i < n; i++) cin >> v[i], v[i]--;

    ll int skill, sum = 0;
    for (int i = 0; i < n; i++) cin >> skill, uni[v[i]].push_back(skill), sum += skill;

    ll int minus[n] = {0};
    vector<pair<ll int, ll int>> p;

    for (auto g : uni) {
        sort(g.second.begin(), g.second.end());

        for (int i = 1; i < g.second.size(); i++) {
            g.second[i] += g.second[i - 1];
            if (g.second.size() % i) {
                minus[i - 1] += g.second[g.second.size() % i - 1];
            }
        }
        p.push_back({g.second.size() + 1, *g.second.rbegin()});
    }

    sort(p.begin(), p.end());

    ll int to_minus = 0;
    ll int j = 0;
    for (int k = 1; k <= n; k++) {
        while (j < p.size() && p[j].first == k) to_minus += p[j].second, j++;
        cout << sum - minus[k - 1] - to_minus << " ";
    }
    NL
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