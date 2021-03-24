// Question: https://practice.geeksforgeeks.org/problems/bbt-counter4914/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=f1fa29e6c070000331fdc9edc4ce897a&pid=704986&user=amanguptarkg6

// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int countBT(int h) { 
        int MOD = 1e9+7;
        long long int dp[h+1];
        dp[0] = dp[1] = 1;
        
        for(int i=2;i<=h;i++){
            long long int x = dp[i-1];
            long long int y = dp[i-2];
            
            dp[i] = ( 
                ( (x*x) % MOD ) +
                ( ( 2*( (x*y)%MOD) ) % MOD)
            ) % MOD;
        }
        
        return dp[h];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}
  // } Driver Code Ends