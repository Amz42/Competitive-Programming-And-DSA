// Question: https://practice.geeksforgeeks.org/problems/pairs-with-specific-difference/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=6610cda4fb2c35be91cf761c4a9fa9ed&pid=702754&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K);

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;

		cout<<maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}
// } Driver Code Ends



int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K){
    sort(arr,arr+N, greater<int>());
    
    int answer = 0, i = 0;
    
    while(i<N-1){
        if(arr[i]-arr[i+1]<K){
            answer += arr[i]+arr[i+1];
            i+=2;
        }else i++;
    }
    
    return answer;
}