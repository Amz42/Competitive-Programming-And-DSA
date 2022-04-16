// Question: https://www.codingninjas.com/codestudio/guided-paths/hack-with-infy-preparation-path/content/125342/offering/1468982

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int *getProductArrayExceptSelf(int *arr, int n){
    int *v = new int[n];
    
    long long last = 1;
    for(int i=0;i<n;i++){
        v[i] = last;
        last = (last * arr[i]) % MOD;
    }
    
    last = 1;
    for(int i=n-1;i>=0;i--){
        v[i] = (v[i] * last) % MOD;
        last = (last * arr[i]) % MOD;
    }
    
    return v;
}

int main(){
    return 0;
}