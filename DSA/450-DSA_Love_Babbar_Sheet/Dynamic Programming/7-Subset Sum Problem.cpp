// Question: https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=030d829cd3e3b27f35832598544fe488&pid=704573&user=amanguptarkg6

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[]){
        int sum = 0;
        for(int i=0;i<N;i++) sum += arr[i];
        
        // if total sum is odd then it is not possible
        if(sum&1) return 0;
        
        // dividing sum by 2
        sum >>= 1;
        
        // stores whether i-th sum is possible using any subset of given set
        bool dp[sum+1]={0}; dp[0] = 1;
        
        for(int i=0;i<N;i++){
            for(int j=sum; j>0;j--){
                // if sum-to-make is smaller than current element
                if(j<arr[i]) break;
                // if corresponding part of sum is formed by any other subset
                if(dp[j-arr[i]]) dp[j] = 1;
            }
        }
        
        return dp[sum];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends