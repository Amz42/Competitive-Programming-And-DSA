// Question: https://practice.geeksforgeeks.org/problems/coin-change2448/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=cb752f83c95b6e20778882343f946147&pid=704100&user=amanguptarkg6

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
  public:
    long long int count( int S[], int m, int n ){
        
        long long int dp[m+1][n+1];
        
        for(int coin=0;coin<=m;coin++){
            for(int sum=0;sum<=n;sum++){
                if(coin==0){
                    // if there's no coin, nothing can be made
                    dp[coin][sum] = 0;
                    continue;
                }
                if(sum==0){
                    // there's always one way to make sum = 0 regardless of coin selected
                    dp[coin][sum] = 1;
                    continue;
                }
                
                dp[coin][sum] = dp[coin-1][sum];
                // if current selected coin is <= sum to be formed 
                if(S[coin-1]<=sum) dp[coin][sum] += dp[coin][sum-S[coin-1]];
            }
        }
        
        
        return dp[m][n];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
}  // } Driver Code Ends