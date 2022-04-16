// Question: https://www.codingninjas.com/codestudio/guided-paths/hack-with-infy-preparation-path/content/125342/offering/1468977

#include <bits/stdc++.h>
using namespace std;

int bestInsertPos(vector<int> arr, int n, int m){    
    int l = 0, r = n-1;
    while(l<=r){
        int mid = l + ( r - l ) / 2;
        if(arr[mid] == m) return mid;
        else if(arr[mid]>m) r = mid - 1;
        else l = mid + 1;
    }
    
    return l;
}

int main(){
    return 0;
}