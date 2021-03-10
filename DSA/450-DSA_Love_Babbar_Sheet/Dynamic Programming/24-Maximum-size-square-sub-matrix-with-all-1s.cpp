// Question: https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=7f6381e3361d01b5f9e0edca2ca691a7&pid=705423&user=amanguptarkg6

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int dp[n+1][m+1];
        int answer = 0;
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0){
                    dp[i][j] = 0;
                    continue;
                }
                
                if(mat[i-1][j-1])
                    dp[i][j] = min({
                        dp[i-1][j],
                        dp[i-1][j-1],
                        dp[i][j-1]
                    }) + 1;
                else dp[i][j] = 0;
                
                answer = max(dp[i][j], answer);
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
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends