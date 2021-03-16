// Question: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=31d8c78f2145a32e57a31ccc09f671b9&pid=700408&user=amanguptarkg6

// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> answer;
    
    void dfs(int i, int j, int n, vector<vector<int>> &m, string s){
        if(i<0 || i>=n || j<0 || j>=n || m[i][j] == 0) return;
        if(i == n-1 && j == n-1) answer.push_back(s);
        
        m[i][j] = 0;
        dfs(i-1, j, n, m, s + "U"); // UP
        dfs(i+1, j, n, m, s + "D"); // DOWN
        dfs(i, j-1, n, m, s + "L"); // LEFT
        dfs(i, j+1, n, m, s + "R"); // RIGHT
        m[i][j] = 1;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        answer.clear();
        dfs(0, 0, n, m, "");
        sort(answer.begin(), answer.end());
        return answer;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends