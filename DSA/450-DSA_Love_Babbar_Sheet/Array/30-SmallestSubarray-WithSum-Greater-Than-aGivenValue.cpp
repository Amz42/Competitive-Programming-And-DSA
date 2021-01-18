// Question: https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=a8394a57358e83a424b2bdc49ced1254&pid=702894&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;
int sb(int arr[], int n, int x);
int main() {
	int t; cin>>t; while(t--){
		int n,x; cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		cout<<sb(a,n,x)<<endl;
	}
	return 0;
}

int sb(int a[], int n, int x){
    int sum = 0, l=0;
    int answer = INT_MAX;
    
    for(int i=0;i<n;i++){
        sum += a[i];
        while(sum-a[l]>x) l++, sum-=a[l-1];
        if(sum>x) answer = min(answer, i-l+1);
    }
    
    return answer;
}