// Question: https://practice.geeksforgeeks.org/problems/pair-in-array-whose-sum-is-closest-to-x1124/1#
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=041d3d7a84c44ed6bb0248e91de42b75&pid=703192&user=amanguptarkg6

//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    vector<int> sumClosest(vector<int> a, int x){
        int l = 0, r = a.size()-1;
        
        vector<int> ans = {a[l], a[r]};
        while(l<r){
            if( abs(x - (ans[0]+ans[1])) > abs(x - (a[l]+a[r])) )
                ans[0] = a[l], ans[1] = a[r];
            if(x - (a[l]+a[r]) < 0)
                r--;
            else
                l++;
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumClosest(arr, x);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends