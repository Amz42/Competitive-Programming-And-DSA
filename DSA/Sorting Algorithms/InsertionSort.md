### Insertion Sort

```c++
#include <bits/stdc++.h>
using namespace std;

// Time Complexity:
//      Worst Case: O(n²)
//      Best Case: O(n)
// Space Complexity: O(1) (As it is an in-place sorting Algorithm)

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int e = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > e) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = e;
    }
}



int main(){
    int a[] = { 2, 27, 4, 3, 8, 17, 3, 9, 10, 1 };
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Array: ";
    for(auto k: a) cout << k << " ";
    
    cout << endl;

    insertionSort(a, n);

    cout << "Sorted Array: ";
    for(auto k: a) cout << k << " ";

    return 0;
}
```