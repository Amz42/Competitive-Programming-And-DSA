// Article: https://www.geeksforgeeks.org/heap-sort/

#include <iostream>
using namespace std;

void Heapify(int i,int n, int a[]){
    int l = 2*i+1;
    int r = 2*i+2;
    int largest = i;
    if(l<n && a[l]>a[i]) largest = l;
    if(r<n && a[r]>a[largest]) largest = r;

    if(largest != i){
        swap(a[i], a[largest]);
        Heapify(largest, n, a);
    }
}

void BuildMaxHeap(int a[], int n){
    for(int i=n/2;i>=0;i--) Heapify(i, n, a);
}

void Heap_Sort(int a[], int n){
    BuildMaxHeap(a,n);
    int sorted_size = n;
    while(sorted_size>1){
        swap(a[sorted_size-1], a[0]);
        Heapify(0, sorted_size-1, a);
        sorted_size--;
    }
}

int main(){

    int n = 8;
    int a[n] = {8,7,6,5,4,3,2,1};

    cout<<"Unsorted Array: ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";

    Heap_Sort(a,n);

    cout<<"\nSorted Array using Heap Sort: ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";

    return 0;
}