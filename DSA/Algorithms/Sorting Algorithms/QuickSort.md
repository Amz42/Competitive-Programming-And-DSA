### Quick Sort

```c++
#include <bits/stdc++.h>
using namespace std;

// Time Complexity:
//      Worst Case: O(n²)
//      Best Case: O(nlog(n))
// Space Complexity: O(1) (As it is an in-place sorting Algorithm)

int partition(int a[], int l , int r) {
    int p = l - 1;
    int pivot = a[r];

    for (int i = l; i < r; i++) {
        if (a[i] < pivot)
            swap(a[++p], a[i]);
    }

    swap(a[++p], a[r]);

    return p;
}

void quickSort(int a[], int l, int r) {
    if (r - l < 1) return;

    int mid = partition(a, l, r);
    quickSort(a, l, mid - 1);
    quickSort(a, mid + 1, r);
}



int main(){
    int a[] = { 2, 27, 4, 3, 8, 17, 3, 9, 10, 1 };
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Array: ";
    for(auto k: a) cout << k << " ";
    
    cout << endl;

    quickSort(a, 0, n - 1);

    cout << "Sorted Array: ";
    for(auto k: a) cout << k << " ";

    return 0;
}
```