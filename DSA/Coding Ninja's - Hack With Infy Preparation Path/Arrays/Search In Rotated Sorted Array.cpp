// Question: https://www.codingninjas.com/codestudio/guided-paths/hack-with-infy-preparation-path/content/125342/offering/1468973

#include <bits/stdc++.h>
using namespace std;

int pivot(int* arr, int low, int high){
    while(low<high){
        int mid = low + ( high - low ) / 2;
        if(arr[mid] > arr[high]) low = mid + 1;
        else high = mid;
    }
    return low;
}

int bsearch(int* arr, int l, int r, int key){
    while(l<r){
        int mid = l + ( r - l ) / 2;
        if(arr[mid] == key) return mid;
        else if(arr[mid]<key) l = mid + 1;
        else r = mid;
    }
    
    return -1;
}

int search(int* arr, int n, int key){
    int pvt = pivot(arr, 0, n-1);
    
    if(arr[pvt] == key) return pvt;
    
    return max(
        bsearch(arr, 0, pvt-1, key),
        bsearch(arr, pvt, n-1, key)
    );
}

int main(){
    return 0;
}