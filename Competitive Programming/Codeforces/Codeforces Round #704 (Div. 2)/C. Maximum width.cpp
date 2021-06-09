// Question: https://codeforces.com/problemset/problem/1492/C

#include <bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define mkpr        make_pair
#define all(v)      v.begin(),v.end()
using namespace std;


const int ten5 = (1e5);
const int MOD = (1e9 + 7);



void answer_nikalo() {
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;

    vector<int> mnp(m);
    int i = 0, j = 0;

    while (j < m) {
        if (s[i] == t[j]) mnp[j++] = i;
        i++;
    }

    int answer = 0;
    i = n - 1, j = m - 1;
    while (j > 0) {
        if (s[i] == t[j]) {
            answer = max(answer, i - mnp[j - 1]);
            j--;
        }
        i--;
    }

    cout << answer;
    return;
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