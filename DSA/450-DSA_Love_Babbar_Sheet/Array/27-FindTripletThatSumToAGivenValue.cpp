// Question: https://practice.geeksforgeeks.org/problems/triplet-sum-in-array/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=b07d74fb82acad18256d6cc0dd383b29&pid=701241&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

bool find3Numbers(int a[], int n, int k){
    sort(a, a+n);
    
    for(int i=0;i<n-2;i++){
        int l=i+1, r=n-1;
        while(l<r){
            int sum = a[i] + a[l] + a[r];
            if(sum == k) return true;
            else if(sum < k) l++;
            else r--;
        }
    }    
    return false;
}

int main(){
	int T; cin>>T; while(T--){
		int N,sum; cin>>N>>sum;
		int i,A[N];
		for(i=0;i<N;i++) cin>>A[i];
        cout << find3Numbers(A, N, sum) << endl;
    }
}