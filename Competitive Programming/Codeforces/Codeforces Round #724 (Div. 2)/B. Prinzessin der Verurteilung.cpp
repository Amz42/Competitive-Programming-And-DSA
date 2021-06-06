// Question: https://codeforces.com/contest/1536/problem/B
// Solution: https://codeforces.com/contest/1536/submission/118614912

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


vector<string> v;
void fun(string s, int l) {
    if (l) v.push_back(s);
    if (l == 3) {
        return;
    }

    for (char c = 'a'; c <= 'z'; c++)
        fun(s + c, l + 1);
}



void solve(int tc) {
    int n; cin >> n;
    string s; cin >> s;

    vector<string> a;
    for (int i = 0; i < n; i++) {
        string d = "";
        for (int j = i; j < n; j++) {
            if (j - i > 3) break;
            d += s[j];
            a.push_back(d);
        }
    }

    set<string> st(a.begin(), a.end());

    vector<string> g(st.begin(), st.end());

    sort(g.begin(), g.end(), [&](string & x, string & y) {
        if (x.size() != y.size()) return (x.size() < y.size());
        for (int i = 0; i < x.size(); i++) {
            if (x[i] != y[i])
                return (x[i] < y[i]);
        }
    });

    // for (auto k : g) cout << k << endl;

    int i = 0;
    while (true) {
        if (g[i] != v[i]) {
            // cout << "done ";
            cout << v[i]; NL
            return;
        }
        i++;
    }
}






int main() {
    optimize
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    long long int tests = 1;

    fun("", 0);

    sort(v.begin(), v.end(), [&](string & a, string & b) {
        if (a.size() != b.size()) return (a.size() < b.size());
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i])
                return (a[i] < b[i]);
        }
    });

    cin >> tests;

    // cout << v.size(); NL
    // for (auto k : v) cout << k << endl;

    for (ll int test_case = 1; test_case <= tests; test_case++) {
        solve(test_case);
    }

    // cerr << "Execution Time : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}