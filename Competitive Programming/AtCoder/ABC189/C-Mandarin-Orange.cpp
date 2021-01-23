// Question: https://atcoder.jp/contests/abc189/tasks/abc189_c
// Solution: https://atcoder.jp/contests/abc189/submissions/19617168

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


long long getMaxArea(long long arr[], int n) {
	stack<int> st;
	int left[n];

	long long int answer = 0;

	// finding first smaller bar on left side
	for (int i = 0; i < n; i++) {
		while (!st.empty() && arr[st.top()] >= arr[i] ) st.pop();
		left[i] = st.empty() ? i : i - st.top() - 1;
		st.push(i);
	}

	while (!st.empty()) st.pop();

	// finding first smaller bar on right side & calculating area alongside
	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() && arr[st.top()] >= arr[i] ) st.pop();
		long long int area = (
		                         left[i] +                               // bars on left side
		                         1 +                                     // current bar
		                         ( st.empty() ? n - i - 1 : st.top() - i - 1 ) // bars on right side
		                     ) * arr[i];                                 // height of current bar
		answer = max(answer, area);                 // maximising the area
		st.push(i);
	}

	return answer;
}



void solve() {
	int n; cin >> n;
	long long arr[n];
	fori(0, n) cin >> arr[i];
	cout << getMaxArea(arr, n);
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
		solve();
	}

	cerr << "Execution Time : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}