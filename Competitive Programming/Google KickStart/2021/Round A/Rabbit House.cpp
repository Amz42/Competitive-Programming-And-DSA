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




int n, m;
int dir[4][2] = {
	{ -1, 0}, // up
	{ +1, 0}, // down
	{0, -1}, // left
	{0, +1} // right
};
bool valid(int i, int j) {
	return !(i < 0 || j < 0 || i >= n || j >= m);
}

void solve(int tc) {
	cin >> n >> m;

	ll int a[n][m], original[n][m];
	bool processed[n][m];
	priority_queue<pair<ll int, pair<ll int, ll int>>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			q.push({a[i][j], { i, j}});
			processed[i][j] = 0;
			original[i][j] = a[i][j];
		}
	}



	ll int answer = 0;

	while (!q.empty()) {
		auto k = q.top(); q.pop();
		ll int i = k.second.first;
		ll int j = k.second.second;
		if (processed[i][j]) continue;
		processed[i][j] = 1;

		for (int g = 0; g < 4; g++) {
			ll int x = i + dir[g][0];
			ll int y = j + dir[g][1];

			if (valid(x, y) && a[i][j] - a[x][y] > 1 && !processed[x][y]) {
				// answer += (a[i][j] - 1 - a[x][y]);
				a[x][y] = a[i][j] - 1;
				q.push({a[x][y], {x, y} });
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// cout << a[i][j] << " ";
			answer += (a[i][j] - original[i][j]);
		}
		// NL
	}

	cout << "Case #" << tc << ": " << answer; NL
}






int main() {
	optimize

	long long int tests = 1;

	cin >> tests;

	for (ll int test_case = 1; test_case <= tests; test_case++) {
		solve(test_case);
	}

	return 0;
}