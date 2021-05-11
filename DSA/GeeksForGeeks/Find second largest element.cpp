// Question: https://practice.geeksforgeeks.org/problems/find-second-largest-element2406/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=137389af4646639f59e18aade47dc2fd&pid=702667&user=amanguptarkg6

/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
   public:
    int print2largest(int arr[], int n){
    	int x = -1, y = -1;
    	for(int i=0;i<n;i++){
    	    if(arr[i]>y) x = y, y = arr[i];
    	    else if(arr[i]>x && arr[i]<y) x = arr[i];
    	}
    	
    	return x;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	      cin>>arr[i];
	    Solution ob;  
	    int ans=ob.print2largest(arr, n);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}
  // } Driver Code Ends