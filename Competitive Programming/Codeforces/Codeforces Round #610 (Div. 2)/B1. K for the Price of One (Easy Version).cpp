// Question: https://codeforces.com/contest/1282/problem/B1
// Solution: https://codeforces.com/contest/1282/submission/114099994

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
    int n, p, k; cin >> n >> p >> k;
    vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    // cumulative frequency for starting (k-1) objects
    for (int i = 1; i <= k - 2; i++) a[i] += a[i - 1];

    // leaving k-th object as it'll pick all k objects from starting

    // calculating for further objects from (k+1) to n-th...
    for (int i = k; i < n; i++) a[i] += a[i - k];

    // finding the answer
    int answer = 0;
    for (int i = 0; i < n; i++) if (a[i] <= p) answer = i + 1;

    cout << answer;
    NL
    return;
}

// APPROACH:
// It's obvious to pick cheaper object first than expensive one.
// Till (k-1)th object each can be bought individually only (i.e. without offer)
// K-th object will always pick k-th + previous (k-1) objects
// Further, (k+1),(k+2),....(n-th) object will pick
// their previous (k-1) objects & other pevious objects...




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