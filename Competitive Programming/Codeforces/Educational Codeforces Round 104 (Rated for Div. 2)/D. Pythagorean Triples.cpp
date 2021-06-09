// Question: https://codeforces.com/contest/1487/problem/D

#include <bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define mkpr        make_pair
#define all(v)      v.begin(),v.end()
using namespace std;


const int ten5 = (1e5);
const int MOD = (1e9 + 7);



void answer_nikalo() {
    ll int n; cin >> n;
    ll int a = sqrt(2 * (n - 1) + 1);

    int answer = 0;
    for (ll int i = 2; i <= a; i++) {
        ll int b1 = i * i - 1;
        if (b1 % 2 == 0) answer++;
    }

    cout << answer << endl;
    return;
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