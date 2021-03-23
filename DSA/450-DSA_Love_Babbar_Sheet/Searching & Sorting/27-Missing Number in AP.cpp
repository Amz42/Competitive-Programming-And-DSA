// Question: https://practice.geeksforgeeks.org/problems/arithmetic-number/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=a27038dc39fefeb825cc819d75d7708e&pid=705133&user=amanguptarkg6

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int inSequence(int A, int B, int C){
        if(!C) return A==B;
        return (
            (B-A)%C == 0 &&
            (B-A)/C >= 0
        );
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}  // } Driver Code Ends