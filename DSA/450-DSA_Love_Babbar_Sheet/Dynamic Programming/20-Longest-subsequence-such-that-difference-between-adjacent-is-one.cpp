// Question: https://practice.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one4724/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=84adcca382d6c6d9fdd68f4669f0a9c8&pid=704413&user=amanguptarkg6

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int longestSubsequence(int n, int a[]){
        if(n<1) return 0;
        
        int dp[n];
        int answer = 1;
        
        for(int i=0;i<n;i++){
            int mx = 0;
            for(int j=0;j<i;j++){
                if( abs(a[i]-a[j]) == 1 ) mx = max(mx, dp[j]);
            }
            dp[i] = mx + 1;
            answer = max(dp[i], answer);
        }
        
        return answer;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends