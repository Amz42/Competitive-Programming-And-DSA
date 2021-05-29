```c++
#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(nlog(n))
// Space Complexity: O(1) (As it is an in-place sorting Algorithm)

void heapify(int index, int size, int a[]) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    int ideal = index;
    if (left < size && a[left] > a[ideal]) ideal = left;
    if (right < size && a[right] > a[ideal]) ideal = right;

    if (index != ideal) {
        swap(a[index], a[ideal]);
        heapify(ideal, size, a);
    }

    return;
}

void buildMaxHeap(int a[], int n) {
    for (int i = n / 2; i >= 0; i--) {
        heapify(i, n, a);
    }
}

void heapSort(int a[], int n) {
    buildMaxHeap(a, n);

    int size = n;
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(0, i, a);
    }
}



int main(){
    int a[] = { 2, 27, 4, 3, 8, 17, 3, 9, 10, 1 };
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Array: ";
    for(auto k: a) cout << k << " ";
    
    cout << endl;

    heapSort(a, n);

    cout << "Sorted Array: ";
    for(auto k: a) cout << k << " ";

    return 0;
}
```