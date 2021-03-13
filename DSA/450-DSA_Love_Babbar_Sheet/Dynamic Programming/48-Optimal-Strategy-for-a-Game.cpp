// Question: https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=a8bc10e9e9faa095f95ab5d3ff92c82d&pid=701421&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

long long dp[101][101];
long long fun(int l, int r, int a[]){
    if(l>r) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    
    long long w = a[l] + fun(l+1, r-1, a);
    long long x = a[l] + fun(l+2, r, a);
    long long y = a[r] + fun(l+1, r-1, a);
    long long z = a[r] + fun(l, r-2, a);
    
    return dp[l][r] = max(
        min(w,x),
        min(y,z)
    );
}

long long maximumAmount(int arr[], int n) {
    memset(dp ,-1, sizeof(dp));
    return fun(0, n-1, arr);
}


// { Driver Code Starts.

int main() {
    
    //taking total testcases
	int T;
	cin>>T;
	while(T--)
	{
	    //taking number of elements
	    int N;
	    cin>>N;
	    
	    int A[N];
	    
	    //inserting the elements
	    for(int i=0;i<N;i++)
	    cin>>A[i];
	    
	    //calling function maximumAmount()
	    cout<<maximumAmount(A,N)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends