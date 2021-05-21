// Question: https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=25eefc47dcb06b685f1b4a89b5167538&pid=702678&user=amanguptarkg6

#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *a, int n) {
        int *ans = new int[2];
        
        for(int i=0;i<n;i++){
            if(a[abs(a[i])-1]>0)
                a[abs(a[i])-1] *= -1;
            else
                ans[0] = abs(a[i]);
        }
        
        for(int i=0;i<n;i++)
            if(a[i]>0)
                ans[1] = i+1;
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends