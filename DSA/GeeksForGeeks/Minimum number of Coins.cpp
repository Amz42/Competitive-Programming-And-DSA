// Question: https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=68a9b98dc2b75e2ea911a20b389d33e6&pid=704439&user=amanguptarkg6

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N){
        int coins[10] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        
        vector<int> answer;
        
        int i = 9;
        while(N){
            int count = N/coins[i];
            N %= coins[i];
            
            while(count--) answer.push_back(coins[i]);
            i--;
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
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends