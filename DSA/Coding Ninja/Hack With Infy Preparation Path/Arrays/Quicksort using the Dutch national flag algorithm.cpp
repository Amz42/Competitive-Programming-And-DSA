// Question: https://www.codingninjas.com/codestudio/guided-paths/hack-with-infy-preparation-path/content/125342/offering/1468971

#include <bits/stdc++.h>
using namespace std;

void partition(vector<int> &a, int low, int high, int& i, int& j){    
    int pivot = a[high];
    int mid = low;
    while(mid<=high){
        if(a[mid]<pivot) swap(a[low++], a[mid++]);
        else if(a[mid] == pivot) mid++;
        else swap(a[mid], a[high--]);
    }
    
    i = low - 1;
    j = mid;
}

void quicksort(vector<int> &arr, int low, int high){
    if(low>high) return;
    if (high - low <= 1) {
        if (arr[high] < arr[low])
            swap(arr[high], arr[low]);
        return;
    }
    
    int i,j;
    partition(arr, low, high, i, j);
    quicksort(arr, low, i);
    quicksort(arr, j, high);
}

vector<int> quickSortUsingDutchNationalFlag(vector<int> &arr){
    int n = arr.size();
    quicksort(arr, 0, n-1);
    return arr;
}

int main(){
    return 0;
}