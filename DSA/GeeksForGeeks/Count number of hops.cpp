// Question: https://practice.geeksforgeeks.org/problems/count-number-of-hops-1587115620/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=9e9171ea893172e0a6212881a02812cf&pid=701423&user=amanguptarkg6


#include <bits/stdc++.h>
using namespace std;
 // } Driver Code Ends



class Solution{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n){
        const int MOD = 1e9+7;
        long long int dp[n+1] = {0}; dp[0] = 1;
        
        for(int i=1;i<=n;i++){
            if(i-1>=0) dp[i] = (dp[i] + dp[i-1]) % MOD;
            if(i-2>=0) dp[i] = (dp[i] + dp[i-2]) % MOD;
            if(i-3>=0) dp[i] = (dp[i] + dp[i-3]) % MOD;
        }
        
        return dp[n];
    }
};


// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}
  // } Driver Code Ends