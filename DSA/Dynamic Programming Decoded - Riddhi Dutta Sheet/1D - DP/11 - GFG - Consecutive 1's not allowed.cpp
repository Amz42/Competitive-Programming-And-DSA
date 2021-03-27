// Question: https://practice.geeksforgeeks.org/problems/consecutive-1s-not-allowed1912/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=0be7d97f5669a2cfffbc48ce86fd0d3a&pid=702777&user=amanguptarkg6

#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    int MOD = 1e9+7;
	    int dp[n+1]; dp[1] = 2; dp[2] = 3;
	    for(int i=3;i<=n;i++) dp[i] = (dp[i-1] + dp[i-2]) % MOD;
	    
	    return dp[n];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends