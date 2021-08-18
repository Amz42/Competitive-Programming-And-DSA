#include <bits/stdc++.h>
#define ll long long
using namespace std;



class SegmentTree {
    int n;
    int ql , qr, update_index, update_value;
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
    void ST_PointUpdate(int index, int l, int r) {
        if (l == r) {
            a[update_index] = update_value;
            tree[index] = update_value;
            return;
        }

        int mid = l + (r - l) / 2;
        if (l <= update_index && update_index <= mid)
            ST_PointUpdate(left(index), l, mid);
        else
            ST_PointUpdate(right(index), mid + 1, r);
        tree[index] = combine(tree[left(index)], tree[right(index)]);
    }
public:
    ll int query(int QueryLeftBound, int QueryRightBound) {
        ql = QueryLeftBound;
        qr = QueryRightBound;
        return STquery(1, 1, n);
    }
    void point_update(int idx, int val) {
        update_index = idx;
        update_value = val;
        ST_PointUpdate(1, 1, n);
    }
};