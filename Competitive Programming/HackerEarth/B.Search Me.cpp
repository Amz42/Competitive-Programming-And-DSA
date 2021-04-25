// Question: https://www.hackerearth.com/practice/algorithms/string-algorithm/string-searching/practice-problems/algorithm/search-me/
// Solution: https://www.hackerearth.com/submission/56780666/

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
 
 
 
string text;
string pattern = "to the";
 
bool match(int l) {
    for (int i = 0; i < pattern.size(); i++)
        if (text[l + i] != pattern[i]) return false;
    return true;
}
 
void solve(int tc) {
    getline(cin, text);
 
    for (int i = 0; i + pattern.size() <= text.size(); i++) {
        if (match(i)) {
            if(i>0 && text[i-1]!=' ') continue;
            if(i+pattern.size()<text.size() && text[i+pattern.size()]!=' ') continue;
            cout << "YES";
            return;
        }
    }
 
    cout << "NO";
    return;
}
 
 
 
 
 
 
int main() {
    optimize
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
 
    long long int tests = 1;
 
    // cin >> tests;
 
    for (ll int test_case = 1; test_case <= tests; test_case++) {
        solve(test_case);
    }
    return 0;
}