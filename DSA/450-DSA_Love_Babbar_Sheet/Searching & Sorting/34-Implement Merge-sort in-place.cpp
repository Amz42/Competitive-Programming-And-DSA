// Article: https://www.geeksforgeeks.org/in-place-merge-sort/
// THIS IS INPLACE IMPROVEMENT OF MERGE SORT IS CALLED SHELL SORT

#include <bits/stdc++.h>
using namespace std;

void InplaceMerge(int a[], int start, int end) {
	int gap = end - start + 1;
	while (gap) {
		for (int i = start; i + gap <= end; i++) {
			if (a[i] > a[i + gap]) swap(a[i], a[i + gap]);
		}
		if (gap == 1) break;
		gap = (gap + 1) / 2;
	}
}

void MergeSort(int a[], int l, int r) {
	if (l < r) {
		int mid = (l + r) / 2;
		MergeSort(a, l, mid);
		MergeSort(a, mid + 1, r);
		InplaceMerge(a, l, r);
	}
}

int main(){
    int a[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(a) / sizeof(a[0]);

	cout << "Elements Of Array: ";
	for (auto k : a) cout << k << " ";
	cout << endl;

	MergeSort(a, 0, n - 1);

	cout << "Sorted Array: ";
	for (auto k : a) cout << k << " ";
    
    return 0;
}