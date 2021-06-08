### Bubble Sort

```c++
#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n²)
// Space Complexity: O(1) (As it is an in-place sorting Algorithm)

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}


int main(){
    int a[] = { 2, 27, 4, 3, 8, 17, 3, 9, 10, 1 };
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Array: ";
    for(auto k: a) cout << k << " ";
    
    cout << endl;

    bubbleSort(a, n);

    cout << "Sorted Array: ";
    for(auto k: a) cout << k << " ";

    return 0;
}
```