// Question: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=831648c0aca22df59a69cd07f716547a&pid=701431&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Returns the maximum value that  
// can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) {
   long long int dp[n+1][W+1];
   
   for(int item=0;item<=n;item++){
       for(int weight=0; weight<=W; weight++){
           // if no item is selected or 0 weight is chosen to be filled then value will be zero
           if(item==0 || weight==0){
               dp[item][weight] = 0;
               continue;
           }
           
           // if current item can be chosen for current weight
           if(wt[item-1]<=weight){
               dp[item][weight] = max(
                   dp[item-1][weight],                          // 0 - not choosing this item
                   val[item-1]+dp[item-1][weight-wt[item-1]]    // 1 - choosing this item
                );
           }else{
            // current item can not be chosen for current weight
              dp[item][weight] = dp[item-1][weight];
           }
       }
   }
   
   return dp[n][W];
}





// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        
        //calling method knapSack()
        cout<<knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends