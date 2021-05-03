// Question: https://www.codingninjas.com/codestudio/guided-paths/hack-with-infy-preparation-path/content/125342/offering/1468970

#include <bits/stdc++.h>
using namespace std;

void sort012(int *arr, int n){
    int l = 0, r = n-1;
    
    for(int i=0;i<n;i++){
        if(arr[i]==0) swap(arr[i], arr[l++]);
    }
    
    for(int i=n-1;i>=0;i--){
        if(arr[i]==2) swap(arr[i], arr[r--]);
    }
}

int main(){
    return 0;
}