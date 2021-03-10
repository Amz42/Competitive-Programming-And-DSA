// Question: https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=5f8efb5340a01cccf848e7fc19b8caed&pid=704559&user=amanguptarkg6

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool valid(int i, int j, int N){
        if(i<0 || i>=N || j<0 || j>=N) return 0;
        return 1;
    }
    
    int maximumPath(int N, vector<vector<int>> Matrix){
        int answer = 0;
        int dp[N][N];
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                dp[i][j] = Matrix[i][j] + max({
                   (valid(i-1, j-1, N) ? dp[i-1][j-1] : 0),
                   (valid(i-1, j, N) ? dp[i-1][j] : 0),
                   (valid(i-1, j+1, N) ? dp[i-1][j+1] : 0)
                });
                
                answer = max(answer, dp[i][j]);
            }
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
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends