// Question: https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=9d5f1bd6b08b9c1a324b7ac9599b2bd9&pid=703687&user=amanguptarkg6

#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends



//  For n-th person there are two choices:
//      1) n-th person remains single, we recur 
//          for f(n - 1)
//      2) n-th person pairs up with any of the 
//          remaining n - 1 persons. We get (n - 1) * f(n - 2)

class Solution{
public:
    int countFriendsPairings(int n){
        long long int dp[n+1]; dp[0] = 0; dp[1] = 1; dp[2] = 2;
        for(int i=3;i<=n;i++)
            dp[i] = (
                dp[i-1] % (int)(1e9+7)
                + (
                        ((i-1) % (int)(1e9+7)) *
                        (dp[i-2] % (int)(1e9+7))
                    ) % (int)(1e9+7)
            ) % (int)(1e9+7);
        return dp[n];
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
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends