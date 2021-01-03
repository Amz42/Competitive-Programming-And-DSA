// Question: https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=2c43ec536db32989c686faeda0f1fda3&pid=701215&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubarraySum(int arr[], int n){
    
    // Your code here
    int meh = 0;
    int answer = INT_MIN;
    
    for(int i=0;i<n;i++){
        meh = max(arr[i], meh + arr[i]);
        answer = max(answer, meh);
    }
    
    return answer;
}

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        
        cout << maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends