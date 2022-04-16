// Question: https://www.codingninjas.com/codestudio/guided-paths/hack-with-infy-preparation-path/content/125342/offering/1468992

#include <bits/stdc++.h>
using namespace std;

vector<int> fun(vector<int>a){
    int n = a.size();
    int mx = a[0];
    for(int i=0;i<n;i++) mx = max(mx, a[i]);
    for(int i=0;i<n;i++) a[i] = mx - a[i];
    return a;
}

vector<int> printArrayAfterKOperations(vector<int> &Arr, int N, int K) {
    if(K==0) return Arr;
    vector<int> od = fun(Arr);
    vector<int> ev = fun(od);
    return (K&1 ? od : ev);
}

int main(){
    return 0;
}