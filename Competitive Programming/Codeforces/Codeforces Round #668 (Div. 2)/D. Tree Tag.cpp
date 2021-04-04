// Question: https://codeforces.com/contest/1405/problem/D
// Solution: https://codeforces.com/contest/1405/submission/102091827

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






void solve() {
	int nodes, alice_pos, bob_pos, alice_jump, bob_jump, x, y;
	cin >> nodes >> alice_pos >> bob_pos >> alice_jump >> bob_jump;

	// input adj list
	vector<int> adj[nodes + 1];
	fori(0, nodes - 1) cin >> x >> y, adj[x].push_back(y), adj[y].push_back(x);

	vector <bool> visited(nodes + 1, false);
	vector <int> distance(nodes + 1, -1);

	// DFS
	function<void(int, int)> dfs = [&] (int node, int dist) {
		visited[node] = true;
		distance[node] = dist;

		for (auto k : adj[node]) {
			if (!visited[k]) dfs(k, dist + 1);
		}
	};

	dfs(alice_pos, 0);
	int first_max_end = max_element(distance.begin(), distance.end()) - distance.begin();

	// Distance between Alice & Bob
	int alice_bob_distance = distance[bob_pos];

	// reset distance & visited array
	fill(distance.begin(), distance.end(), -1);
	fill(visited.begin(), visited.end(), false);

	dfs(first_max_end, 0);
	int second_max_end = max_element(distance.begin(), distance.end()) - distance.begin();

	// Diameter of tree
	int diameter = distance[second_max_end];

	if (
	    (alice_bob_distance <= alice_jump) || // in first jump alice can reach bob
	    (alice_jump * 2 >= diameter) || // alice can jump to center of tree & then jump anywhere in tree in a move
	    (bob_jump <= 2 * alice_jump) // worst case: no node possible where bob can jump & alice can't reach
	) cout << "Alice";
	else cout << "Bob";
	NL
	return;
}


// LOGIC:
// Simply find diameter of tree & distance between Alice & Bob
// Case 1: if Alice can jump to Bob in first move
// Case 2: Alice can jump to center of tree & then jump anywhere in single move
// Case 3: No node possible,which is reachable by Bob & not by Alice



int main() {
	optimize
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	long long int tests = 1;

	cin >> tests;

	for (ll int test_case = 1; test_case <= tests; test_case++) {
		solve();
	}

	cerr << "Execution Time : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}