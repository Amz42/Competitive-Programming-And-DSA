// Question: https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=6e3ff93c5627690dedf6f3dfc0321778&pid=704037&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
	public:
	int maxSumIS(int a[], int n){
	    int dp[n]={0};
	    int answer = 0;
	    
	    for(int i=0;i<n;i++){
	        int x = 0;
	        for(int j=0;j<i;j++){
	            if(a[j]<a[i]) x = max(x, dp[j]);
	        }
	        
	        dp[i] = a[i] + x;
	        answer = max(answer, dp[i]);
	    }
	    
	    return answer;
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends