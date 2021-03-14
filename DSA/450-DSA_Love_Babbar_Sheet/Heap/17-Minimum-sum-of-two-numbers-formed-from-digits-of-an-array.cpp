// Question: https://practice.geeksforgeeks.org/problems/minimum-sum4058/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=3361ad70c890d8323b7cd57d09802043&pid=703419&user=amanguptarkg6


//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n){
        sort(arr,arr+n);
        string res = "";
        
        int i = n - 1, carry = 0;
        
        while(i>=0){
            if(i==0) res = to_string(arr[i]+carry) + res;
            else{
                int sum=(arr[i]+arr[i-1]+carry)%10;
                carry = (arr[i]+arr[i-1]+carry)/10;
                res = to_string(sum)+res;
            }
            
            i -= 2;
        }
        
        //If carry is left at last.
        if(i==-1)
            res = to_string(carry) + res;
        
        while(res[0]=='0')
            res.erase(res.begin());
        
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends