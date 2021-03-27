// Question: https://practice.geeksforgeeks.org/problems/ncr1019/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=0961cc9b8003c286c3ff6deb978bf428&pid=704542&user=amanguptarkg6

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:
    int nCr(int n, int r){
        if(n==0 || r>n) return 0;
        if(r==n) return 1;
        if(r==1) return n;
        
        int dp[n]={0}; dp[0] = 1;
        
        for(int i=0;i<n;i++){
            for(int j = n-1; j>0; j--) dp[j] = (dp[j] + dp[j-1]) % (int)(1e9+7);
        }
        
        return dp[r];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends