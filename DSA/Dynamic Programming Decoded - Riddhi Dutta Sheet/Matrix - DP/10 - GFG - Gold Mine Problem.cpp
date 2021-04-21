// Article: https://www.geeksforgeeks.org/gold-mine-problem/
// Question: https://practice.geeksforgeeks.org/problems/gold-mine-problem2608/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=0de465f3a1e34249a17be7318488bb7f&pid=704162&user=amanguptarkg6

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    bool valid(int i, int j, int n, int m){
        return !(i<0 || j<0 || i>=n || j>=m);
    }
public:
    int maxGold(int n, int m, vector<vector<int>> M){
        int answer = 0;
        for(int j=m-1;j>=0;j--){
            for(int i=0;i<n;i++){
                M[i][j] += max({
                    valid(i-1, j+1, n, m) ? M[i-1][j+1] : 0,
                    valid(i, j+1, n, m)   ? M[i][j+1]   : 0,
                    valid(i+1, j+1, n, m) ? M[i+1][j+1] : 0
                });
                answer = max(answer, M[i][j]);
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
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends