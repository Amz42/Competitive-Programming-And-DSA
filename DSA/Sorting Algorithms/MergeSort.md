### Merge Sort

```c++
#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(nlog(n))
// Space Complexity: O(n) (As it is an out-place sorting Algorithm)

void merge(int a[], int l , int mid, int r) {
    int L = mid - l + 1;
    int R = r - mid;

    int x = 0, y = 0;
    int left[L], right[R];
    for (int i = l; i <= mid; i++) left[x++] = a[i];
    for (int i = mid + 1; i <= r; i++) right[y++] = a[i];

    int i = l; x = y = 0;
    while (x < L && y < R) {
        if (left[x] <= right[y]) a[i++] = left[x++];
        else a[i++] = right[y++];
    }

    while (x < L) a[i++] = left[x++];
    while (y < R) a[i++] = right[y++];

    return;
}

void mergeSort(int a[], int l , int r) {
    if (r - l < 1) return;
    int mid = l + (r - l) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    merge(a, l, mid, r);
}



int main(){
    int a[] = { 2, 27, 4, 3, 8, 17, 3, 9, 10, 1 };
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Array: ";
    for(auto k: a) cout << k << " ";
    
    cout << endl;

    mergeSort(a, 0, n - 1);

    cout << "Sorted Array: ";
    for(auto k: a) cout << k << " ";

    return 0;
}
```