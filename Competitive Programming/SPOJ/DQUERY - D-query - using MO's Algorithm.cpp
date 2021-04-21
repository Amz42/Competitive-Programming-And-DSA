// Question: https://www.spoj.com/problems/DQUERY/
// Solution: https://www.spoj.com/status/ns=27751488

/*                                              _                    _  _  ____
                                               / \   _ __ ___  ____ | || ||___ \
                                              / _ \ | '_ ` _ \|_  / | || |_ __) |
                                             / ___ \| | | | | |/ /  |__   _/ __/
                                            /_/   \_\_| |_| |_/___|    |_||_____|
*/
#include <bits/stdc++.h>
#define ll          long long
#define NL          cout<<"\n";
#define ten5        (int)(1e5)
using namespace std;


/////////////////////////////////////////////////////////////////////////////////////////////
//////////////            MO's Algorithm
/////////////////////////////////////////////////////////////////////////////////////////////

const int BLOCK = 700;
struct Query {
	int l, r, index;
};

// Customized Sorting Comparator Function
bool comparator(Query& a, Query& b) {
	if (a.l / BLOCK != b.l / BLOCK)
		return (a.l / BLOCK < b.l / BLOCK);
	return (a.r < b.r);
}

// Array to Store Elements
int a[(int)(3 * 1e4 + 1)];

// Frequency Table
int freq[(int)(1e6 + 1)];

// Answer Array
int answer[2 * ten5 + 1];

// Count of Unique Elements in Query Window
int Count_Unique_Elements = 0;

// To add an element into Query Window
void add(int index) {
	freq[a[index]]++;
	if (freq[a[index]] == 1) Count_Unique_Elements++;
}

// To remove an element from Query Window
void remove(int index) {
	freq[a[index]]--;
	if (freq[a[index]] == 0) Count_Unique_Elements--;
}

void solve(int tc) {
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	int q; cin >> q;
	Query Q[q];
	for (int i = 0; i < q; i++) cin >> Q[i].l >> Q[i].r, Q[i].index = i;

	sort(Q, Q + q, comparator);

	int ML = 0, MR = -1;
	for (Query k : Q) {
		// as it was provided in 1 based indexing
		k.l--, k.r--;

		int L = k.l;
		int R = k.r;

		// extending the window
		// First move the pointer then updateupdate data data
		while (ML > L) add(--ML);
		while (MR < R) add(++MR);

		// reducing the window
		// First update data then move the pointer
		while (ML < L) remove(ML++);
		while (MR > R) remove(MR--);

		answer[k.index] = Count_Unique_Elements;
	}

	// Printing the answer
	for (int i = 0; i < q; i++) cout << answer[i] << endl;
}






int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve(1);
	return 0;
}