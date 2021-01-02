// Article: https://www.geeksforgeeks.org/searching-array-adjacent-differ-k/

#include <bits/stdc++.h>
using namespace std;

void find_X(int a[],int n, int diff, int element){
    int i=0;
    while(i<n){
        if(a[i]==element){
            cout<<element<<" found at index: "<<i;
            return;
        }

        i += max(1, abs(a[i]-element)/diff);
    }

    cout<<element<<" is not present in the given array...";
}

int main(){
    int n = 6; // size of array;
    int arr[]= {2, 4, 5, 7, 7, 6};
    int diff = 2;
    int element = 6;
    find_X(arr,n,diff,element);
}