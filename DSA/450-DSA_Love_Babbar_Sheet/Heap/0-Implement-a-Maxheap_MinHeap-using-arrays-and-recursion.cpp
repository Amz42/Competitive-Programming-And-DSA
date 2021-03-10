// Article: https://www.geeksforgeeks.org/building-heap-from-array/

#include <bits/stdc++.h>
using namespace std;

void Heapify(int a[], int n, int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l<n && a[l]>a[i]) largest = l;
    if(r<n && a[r]>a[largest]) largest = r;

    if(largest != i){
        swap(a[i], a[largest]);
        Heapify(a, n, largest);
    }
}

void BuildMaxheap(int a[], int n){
    for(int i=n/2;i>=0;i--) Heapify(a, n, i);
}

int main(){
    int a[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
    int n = sizeof(a)/sizeof(a[0]);

    cout << "Heap: ";
    for(int i=0;i<n;i++) cout << a[i] << " ";

    BuildMaxheap(a, n);

    cout << "\nMax-Heap: ";
    for(int i=0;i<n;i++) cout << a[i] << " ";

    return 0;
}