// Question: https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1#
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=1e552516529c64c8150d93e38190e425&pid=701418&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // function to count ways to reach mth stair
    int countWays(int m){
        long long int dp[m+1]={0}; dp[0] = 1;
        for(int i=1;i<=m;i++){
            if(i-1>=0) dp[i] += dp[i-1];
            if(i-2>=0) dp[i] += dp[i-2];
            dp[i] %= (int)(1e9+7);
        }
        
        return dp[m];
    }
};

int main(){
    int t; cin >> t; while(t--){
        int m; cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}