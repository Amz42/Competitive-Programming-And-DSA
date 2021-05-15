// Question: https://www.spoj.com/problems/RMQSQ/
// Solution: https://www.spoj.com/status/ns=27892201

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



class SegmentTree {
    int n, ql , qr;
    string type;
    vector<ll int> a, tree;
public:
    /* Note: Store data in vector on 1 based indexing only. */
    SegmentTree(vector<ll int> v, string operation = "sum") {
        n = v.size();
        a = v;
        tree.resize(4 * n + 5);
        type = operation;
        build(1, 1, n);
    }
private:
    int left(int index) { return (index << 1); }
    int right(int index) { return ((index << 1) + 1); }

    ll int combine(ll int l, ll int r) {
        if (type == "sum") return (l + r);
        if (type == "max") return max(l, r);
        if (type == "min") return min(l, r);
        return 0;
    }

    ll int opposite() {
        if (type == "sum") return (0);
        if (type == "max") return (LLONG_MIN);
        if (type == "min") return (LLONG_MAX);
        return 0;
    }

    void build(int index, int l, int r) {
        if (l == r) {
            tree[index] = a[l];
            return;
        }

        int mid = l + (r - l) / 2;
        build(left(index), l, mid);
        build(right(index), mid + 1, r);

        tree[index] = combine(tree[left(index)], tree[right(index)]);
    }

    ll int STquery(int index, int l, int r) {
        // this segment lies outside query range
        if (ql > r || qr < l)
            return opposite();

        // this segment lies inside query range
        if (ql <= l && r <= qr)
            return tree[index];

        // this segment lies partially in query range
        int mid = l + (r - l) / 2;
        ll int LeftSideResult = STquery(left(index), l, mid);
        ll int RightSideResult = STquery(right(index), mid + 1, r);

        return combine(LeftSideResult, RightSideResult);
    }
public:
    ll int query(int QueryLeftBound, int QueryRightBound) {
        ql = QueryLeftBound;
        qr = QueryRightBound;
        return STquery(1, 1, n);
    }
};


void solve(int tc) {
    int n; cin >> n;
    vector<ll int> v(n + 1);
    for (int i = 0; i < n; i++) cin >> v[i + 1];

    SegmentTree st = *new SegmentTree(v, "min");

    int q; cin >> q;
    while (q--) {
        int ql, qr; cin >> ql >> qr;
        ql++; qr++;
        cout << st.query(ql, qr) << endl;
    }
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