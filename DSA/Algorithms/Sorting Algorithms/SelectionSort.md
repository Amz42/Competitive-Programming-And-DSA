### Selection Sort

```c++
#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n²)
// Space Complexity: O(1) (As it is an in-place sorting Algorithm)

void selectionSort(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i])
                swap(a[j], a[i]);
        }
    }
}


int main(){
    int a[] = { 2, 27, 4, 3, 8, 17, 3, 9, 10, 1 };
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Array: ";
    for(auto k: a) cout << k << " ";
    
    cout << endl;

    selectionSort(a, n);

    cout << "Sorted Array: ";
    for(auto k: a) cout << k << " ";

    return 0;
}
```