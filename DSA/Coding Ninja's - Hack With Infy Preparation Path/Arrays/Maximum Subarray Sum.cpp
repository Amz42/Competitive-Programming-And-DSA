// Question: https://www.codingninjas.com/codestudio/guided-paths/hack-with-infy-preparation-path/content/125342/offering/1468965

#include<bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n){
    long long meh = 0, answer = 0;
    
    for(int i=0;i<n;i++){
        meh = max(meh + arr[i], 0LL);
        answer = max(answer, meh);
    }
    
    return answer;
}

int main(){
    return 0;
}