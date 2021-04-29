// Question: https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=6d6ed5ab37967081195dd9d51fedcb91&pid=701420&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[201][201];
    int fun(int egg, int floors){
        if(floors == 0) return 0;
        if(egg == 1) return floors;
        if(dp[egg][floors] != -1)
            return dp[egg][floors];
        
        int answer = INT_MAX;
        
        for(int i=1;i<=floors;i++)
            answer = min(answer, max(fun(egg-1, i-1), fun(egg, floors-i)) ) ;
        
        return dp[egg][floors] = answer + 1;
    }
    
    int eggDrop(int n, int k){
        memset(dp, -1, sizeof dp);
        return fun(n, k);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends