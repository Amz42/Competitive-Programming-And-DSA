// Question: https://practice.geeksforgeeks.org/problems/word-break/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=b475ce7663404ee5e2081ab77f5635f7&pid=702073&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

int wordBreak(string A, vector<string> &B);

int main(){
    int t; cin>>t; while(t--){
        int n; cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S; cin >> S;
            dict.push_back(S);
        }
        string line; cin >> line;
        cout << wordBreak(line, dict) << "\n";
    }
}
// } Driver Code Ends


//User function template for C++

// A : given string to search
// B : vector of available strings

int wordBreak(string A, vector<string> &B){
    int n = A.size();
    bool dp[n+1] = {0}; dp[0] = 1;
    unordered_map<string, bool> mp;
    
    for(auto k: B) mp[k] = true;
    
    for(int j=1;j<n+1;j++){ // ending index
        for(int i=1;i<=j;i++){ // length
            // s.substr(start-index, length);
            if(mp[A.substr(j-i,i)] && dp[j-i]) dp[j] = true;
        }
    }
    
    return dp[n];
}