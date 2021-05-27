// Question: https://practice.geeksforgeeks.org/problems/largest-subsquare-surrounded-by-x0558/1#
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=91f57fb6bfe64688cc002cdbad0673c1&pid=705727&user=amanguptarkg6

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int largestSubsquare(int n, vector<vector<char>> a) {
        int up[n][n], left[n][n];
        
        // left calculation
        for(int i=0;i<n;i++){
            left[i][0] = a[i][0] == 'X' ? 1 : 0;
            for(int j=1;j<n;j++){
                left[i][j] = a[i][j] == 'X' ? left[i][j-1]+1 : 0;
            }
        }
        
        // up calculation
        for(int j=0;j<n;j++){
            up[0][j] = a[0][j] == 'X' ? 1 : 0;
            for(int i=1;i<n;i++){
                up[i][j] = a[i][j] == 'X' ? up[i-1][j]+1 : 0;
            }
        }
        
        int answer = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int d = min(up[i][j], left[i][j]);
                
                while(d > answer){
                    if(up[i][j-d+1] >= d && left[i-d+1][j] >= d)
                        answer = d;
                    d--;
                }
            }
        }
        
        return answer;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<char>> v(N, vector<char>(N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cin >> v[i][j];
        }
        Solution ob;
        cout << ob.largestSubsquare(N, v) << "\n";
    }
}  // } Driver Code Ends