// Question: https://codeforces.com/problemset/problem/1490/F

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
    map<int, int> mp;
    int freq[n + 1] = {0};

    int x;
    for (int i = 0; i < n; i++)
        cin >> x, mp[x]++;

    for (auto k : mp) freq[k.second]++;

    int pref[n + 1] = {0};
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + freq[i] * i;

    // for (auto k : freq) cout << k << " ";

    int answer = n;
    int cnt = 0;

    for (int i = n; i > 0; i--) {
        answer = min({
            answer,
            pref[i - 1] + (n - pref[i]) - i * cnt
        });

        cnt += freq[i];
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