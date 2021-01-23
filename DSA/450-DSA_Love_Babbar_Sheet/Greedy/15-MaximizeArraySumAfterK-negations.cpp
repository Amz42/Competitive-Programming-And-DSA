// Question: https://practice.geeksforgeeks.org/problems/maximize-sum-after-k-negations/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=72c49350a8eb137fc81c7ae1ae246563&pid=702738&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;
#define ll long long

long long int maximizeSum(long long int a[], int n, int k);

int main(){
    int t; cin>>t;
    while(t--){
        int n, k; cin>>n>>k;
        long long int a[n+5];
        for(int i=0;i<n;i++) cin>>a[i];
        cout<<maximizeSum(a, n, k)<<endl;
    }
	return 0;
}

long long int maximizeSum(long long int a[], int n, int k){
    sort(a,a+n);
    
    long long int mini = LLONG_MAX;
    int  negs = 0;
    for(int i=0;i<n;i++){
        if(a[i]<0) negs++;
        mini = min(mini, abs(a[i]));
    }
    
    long long int answer = 0;   
    if(negs>=k){
        for(int i=0;i<k;i++) a[i] = -1*a[i];
        for(int i=0;i<n;i++) answer += a[i];
    }else{
        for(int i=0;i<n;i++) answer += abs(a[i]);
        if((k-negs) & 1) answer -= 2*mini;
    }
    
    return answer;
}