// Article: https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
// Question: https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1#
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=078c6bfe4b294fe021914853daaff87a&pid=704556&user=amanguptarkg6

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    int dp[101][101];
    int MCM(int pivot[], int l, int r){
        if(l==r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        
        int answer = INT_MAX;
        for(int i=l;i<r;i++){
            answer = min(
                answer,
                MCM(pivot, l, i) + MCM(pivot, i+1, r) + pivot[l]*pivot[i+1]*pivot[r+1]
            );
        }
        
        return dp[l][r] = answer;
    }
public:
    int matrixMultiplication(int N, int arr[]){
        memset(dp, -1, sizeof dp);
        return MCM(arr, 0, N-2);
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
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends