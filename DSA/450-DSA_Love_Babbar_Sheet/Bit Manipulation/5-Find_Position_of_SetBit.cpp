// Question: https://practice.geeksforgeeks.org/problems/find-position-of-set-bit3706/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=14fcf8fcfa6d3818cc4293cacba1d5b8&pid=703764&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
  public:
    int findPosition(int n) {
        if(n==0) return -1;
        int pos = 0;
        
        while(n){
            pos += 1;
            if(n&1){
                n >>= 1;
                break;
            }
            n >>= 1;
        }
        
        return (n ? -1 : pos);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}  // } Driver Code Ends