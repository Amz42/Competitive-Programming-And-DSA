// Question: https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1#
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=56a797dee75d725fb53d05dcfab2a68c&pid=701289&user=amanguptarkg6


#include <bits/stdc++.h>
using namespace std;


bool subArrayExists(int arr[], int n);
// Driver code
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
	    	if (subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}// } Driver Code Ends


//Complete this function
bool subArrayExists(int arr[], int n){
    unordered_set<int> mp;
    
    int sum = 0;
    for(int i=0;i<n;i++){
        int k = arr[i];
        sum += k;
        if(k==0 || sum==0 || mp.find(sum)!=mp.end()) return true;
        mp.insert(sum);
    }
    
    return false;
}

// APPROACH:
// keep updating prefix sum & check for any of 3 conditions:-
//      1. sum reaches 0 
//      2. any number from array is 0
//      3. current sum has appeared before