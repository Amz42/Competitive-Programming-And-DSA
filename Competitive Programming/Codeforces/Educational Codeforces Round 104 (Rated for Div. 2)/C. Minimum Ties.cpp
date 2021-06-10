// Question: https://codeforces.com/problemset/problem/1487/C

#include <bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define mkpr        make_pair
#define all(v)      v.begin(),v.end()
using namespace std;


const int ten5 = (1e5);
const int MOD = (1e9 + 7);



void answer_nikalo() {
    int n; cin >> n;
    vector<string> v;

    int m = n - 1;
    string s = "#" + string(m / 2, '1') + (m & 1 ? "-" : "") + string(m / 2, '0');

    for (int i = 0; i < n; i++)
        v.push_back(s.substr(n - i, i) + s.substr(0, n - i));


    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i][j] == '1') cout << "1 ";
            else if (v[i][j] == '0') cout << "-1 ";
            else cout << "0 ";
        }
    }

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