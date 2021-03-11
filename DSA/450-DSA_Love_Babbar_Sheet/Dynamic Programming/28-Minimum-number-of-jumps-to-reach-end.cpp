// Question: https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=420daac7f23a0cb80e41caddc0744776&pid=701393&user=amanguptarkg6


#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



// Function to return minimum number of jumps to end of array
int minJumps(int a[], int n){
    if(n && a[0]==0) return -1;
    
    int jumps = 1;
    int steps = a[0];
    int max_reach = a[0];
    
    for(int i = 1;i<n;i++){
        if(i==n-1) return jumps;
        
        // maximize max reachable point
        max_reach = max(max_reach, i+a[i]);
        
        steps--;
        
        if(steps==0){
            // we must have taken a jump before
            jumps++;
            if(i>=max_reach) return -1;
            
            // number of steps we're able to take now
            steps = max_reach - i;
        }
    }
    
    return -1;
}


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
            
        cout<<minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends