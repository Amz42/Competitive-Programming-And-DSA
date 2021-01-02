// Question: https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1#
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=322aef0a9eaf2cedccd647115a838caf&pid=702139&user=amanguptarkg6

#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > fourSum(vector<int> &a, int k);

// Position this line where user code will be pasted.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) cin >> a[i];
        vector<vector<int> > ans = fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) cout << u << " ";
            cout << "$";
        }
        if (ans.empty()) cout << -1;
        cout << "\n";
    }
    return 0;
}// } Driver Code Ends


// User function template for C++

// arr[] : int input array of integers
// k : the quadruple sum required
vector<vector<int> > fourSum(vector<int> &a, int k) {
    vector<vector<int> > ans;           // answer array
    sort(a.begin(),a.end());            // sort the given array
    
    int n = a.size();                   // size of given array
    
    for(int i=0;i<n-3;i++){
        
        // while last element is equal to current
        if(i>0 && a[i]==a[i-1]) continue;
        
        for(int j=i+1;j<n-2;j++){
            
            // while last element is equal to current
            if(j>i+1 && a[j] == a[j-1]) continue;
            
            int l=j+1, r=n-1;
            
            while(l<r){
                // sum of quadruple
                int tot = a[i]+ a[j] + a[l] + a[r];
                if(tot == k){
                    
                    // storing the quadruple
                    vector<int> v = { a[i], a[j], a[l], a[r] };
                    ans.push_back(v);
                    
                    // moving lower & upper bounds forward
                    l++, r--;
                    while(l<r && a[l] == a[l-1]) l++;
                    while(l<r && a[r] == a[r+1]) r--; 
                }
                
                else if(tot < k) l++;
                else             r--;
            }
        }
    }
    
    return ans;
}