// Question: https://www.codingninjas.com/codestudio/guided-paths/hack-with-infy-preparation-path/content/125342/offering/1468967

#include <bits/stdc++.h>
using namespace std;

long long max(long long a, long long b){
    return (a>b ? a : b);
}

long long kadane(vector<int> &arr, int n, int k){
    long long meh = 0, KDN = -1e15;
    for(int i=0;i<n*k;i++){
        meh += arr[i%n];
        KDN = max(KDN, meh);
        meh = max(meh, 0LL);
    }
    return KDN;
}

long long maxSubSumKConcat(vector<int> &arr, int n, int k){
	long long total = 0;
    for(int i=0;i<n;i++) total += arr[i];
    
    if(k==1) return kadane(arr, n, 1);
    if(total<=0) return kadane(arr, n, 2);
    return (kadane(arr, n, 2) + total * (long long)(k-2));
}

int main(){
    return 0;
}