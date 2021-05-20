// Question: https://codeforces.com/contest/1527/problem/B2
// Solution: https://codeforces.com/contest/1527/submission/116857016

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



bool isPalindrome(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r])
            return false;
        l++, r--;
    }
    return true;
}


void solve(int tc) {
    int n; string s;
    cin >> n >> s;

    int zeros = 0;
    for (auto k : s) if (k == '0') zeros++;

    if (isPalindrome(s)) {
        if (n & 1 && s[n / 2] == '0' && zeros >= 3)
            cout << "ALICE";
        else
            cout << "BOB";
        NL
        return;
    }

    if (n & 1 && s[n / 2] == '0' && zeros == 2) {
        cout << "DRAW"; NL
        return;
    }

    cout << "ALICE"; NL
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